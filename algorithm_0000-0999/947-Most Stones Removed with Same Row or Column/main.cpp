#ifndef __DISJOINT_SETS_HPP__493A883A_6A4F_4328_8CB1_58CB15279742
#define __DISJOINT_SETS_HPP__493A883A_6A4F_4328_8CB1_58CB15279742

#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <iterator>
#include <limits>
#include <map>
#include <set>
#include <type_traits>
#include <utility>
#include <vector>

template <typename Map>
struct FindNoCompress {
    bool operator()(Map& map, typename Map::key_type elem, typename Map::key_type& root) const {
        typename Map::const_iterator itr = map.find(elem);
        if (itr == map.cend()) {
            return false;
        }
        else {
            root = elem;
            while (itr->second != root) {
                root = itr->second;
                itr = map.find(root);
            }

            return true;
        }
    }
};

template <typename Map>
struct FindFullCompress {
    bool operator()(Map& map, typename Map::key_type elem, typename Map::key_type& root) const {
        typename Map::const_iterator itr = map.find(elem);
        if (itr == map.cend()) {
            return false;
        }
        else {
            root = itr->second;
            if (root == elem) {
                return true;
            }

            std::vector<typename Map::key_type> candidates;
            while (true) {
                itr = map.find(root);
                assert(itr != map.cend());

                if (itr->second == root) {
                    break;
                }

                candidates.push_back(elem);
                elem = root;
                root = itr->second;
            }

            for (typename Map::key_type candidate : candidates) {
                map[candidate] = root;
            }

            return true;
        }
    }
};

template<typename Sequence, typename = typename std::enable_if<std::is_unsigned<typename Sequence::value_type>::value>::type>
class SequenceWrapper {
public:
    typedef typename Sequence::value_type value_type;
    typedef value_type key_type;
    typedef value_type mapped_type;

    class Iterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = std::pair<const SequenceWrapper::value_type, SequenceWrapper::value_type&>;
        using pointer = value_type*;
        using const_pointer = const value_type*;
        using reference = value_type&;
        using const_reference = const value_type&;

        Iterator() = default;
        Iterator(const Iterator&) = default;
        Iterator(Iterator&&) = default;

        explicit Iterator(SequenceWrapper& wrapper, SequenceWrapper::value_type index)
            : m_pWrapper(&wrapper)
            , m_val(index, (static_cast<SequenceWrapper::value_type>(m_pWrapper->m_seq.size()) <= index ? m_pWrapper->m_extraVal : m_pWrapper->m_seq[index])) {
        }

        reference operator*() { return m_val; }
        const_reference operator*() const { return m_val; }

        pointer operator->() { return &m_val; }
        const_pointer operator->() const { return &m_val; }

        Iterator& operator++() {
            Sequence& seq = m_pWrapper->m_seq;
            SequenceWrapper::value_type index(m_val.first);
            SequenceWrapper::value_type size(seq.size());
            if (size <= index) {
                return *this;
            }
            else {
                ++index;
                while (index < size && seq[index] == m_pWrapper->m_extraVal) {
                    ++index;
                }

                m_val.~value_type();
                new (&m_val) value_type(index, (size <= index ? m_pWrapper->m_extraVal : seq[index]));
            }

            return *this;
        }

        Iterator operator++(int) {
            Iterator tmp(*this);
            ++(*this);
            return tmp;
        }

        Iterator& operator=(const Iterator& rhs) {
            m_pWrapper = rhs.m_pWrapper;
            m_val.~value_type();
            new (&m_val) value_type(rhs.m_val);

            return *this;
        }

        const Iterator& operator=(const Iterator& rhs) const {
            return const_cast<Iterator*>(this)->operator=(rhs);
        };

        bool operator==(const Iterator& rhs) const {
            return (m_pWrapper == rhs.m_pWrapper && m_val.first == rhs.m_val.first);
        }

        bool operator!=(const Iterator& rhs) const {
            return !(*this == rhs);
        }

    private:
        SequenceWrapper<Sequence>* m_pWrapper;
        value_type m_val;
    };

    typedef Iterator iterator;
    typedef const iterator const_iterator;

    SequenceWrapper()
        : m_seq()
        , m_extraVal(std::numeric_limits<value_type>::max()) {
    }

    SequenceWrapper(const SequenceWrapper&) = default;
    SequenceWrapper(SequenceWrapper&&) = default;

    value_type& operator[](value_type i) {
        if (static_cast<value_type>(m_seq.size()) <= i) {
            m_seq.resize(i + 1, m_extraVal);
        }
        return m_seq[i];
    }

    const value_type& operator[](value_type i) const {
        return const_cast<SequenceWrapper*>(this)->operator[](i);
    }

    void clear() {
        m_seq.clear();
    }

    iterator find(value_type i) {
        if (static_cast<value_type>(m_seq.size()) <= i || m_seq[i] == m_extraVal) {
            return end();
        }
        return iterator(*this, i);
    }

    const_iterator find(value_type i) const {
        return const_cast<SequenceWrapper*>(this)->find(i);
    }

    iterator begin() noexcept {
        for (value_type i = 0, size = static_cast<value_type>(m_seq.size()); i < size; ++i) {
            if (m_seq[i] != m_extraVal) {
                return iterator(*this, i);
            }
        }
        return end();
    }

    const_iterator begin() const noexcept {
        return const_cast<SequenceWrapper*>(this)->begin();
    }

    iterator end() noexcept {
        return iterator(*this, static_cast<value_type>(m_seq.size()));
    }

    const_iterator end() const noexcept {
        return const_cast<SequenceWrapper*>(this)->end();
    }

    const_iterator cbegin() const noexcept {
        return begin();
    }

    const_iterator cend() const noexcept {
        return end();
    }

protected:
    Sequence m_seq;
    value_type m_extraVal;
};

template<typename T, typename Map = std::map<T, T>, typename Find = FindFullCompress<Map>>
class DisjointSets {
public:
    typedef T value_type;
    typedef Map map_type;

    template<typename T1, typename Map1, typename Find1>
    bool operator==(const DisjointSets<T1, Map1, Find1>& rhs) const {
        return (size() == rhs.size() && sets<std::set>() == rhs.template sets<std::set>());
    }

    template<typename T1, typename Map1, typename Find1>
    bool operator!=(const DisjointSets<T1, Map1, Find1>& rhs) const {
        return !(*this == rhs);
    }

    static_assert(std::is_same<T, typename Map::key_type>::value, "value_type must be the same as the underlying container key_type");
    static_assert(std::is_same<T, typename Map::mapped_type>::value, "value_type must be the same as the underlying container mapped_type");

    DisjointSets(const Find& find = Find())
        : m_map()
        , m_find(find)
        , m_size(0) {
    }

    DisjointSets(const DisjointSets&) = default;
    DisjointSets(DisjointSets&&) = default;

    template<typename InputIterator>
    explicit DisjointSets(InputIterator first, InputIterator last, const Find& find = Find())
        : m_map()
        , m_find(find)
        , m_size(0) {
        for (InputIterator itr = first; itr != last; ++itr) {
            merge(itr->first, itr->second);
        }
    }

    explicit DisjointSets(std::initializer_list<std::pair<const T, T>> l, const Find& find = Find())
        : m_map()
        , m_find(find)
        , m_size(0) {
        for (const std::pair<const T, T>& p : l) {
            merge(p.first, p.second);
        }
    }

    void clear() {
        m_map.clear();
        m_size = 0;
    }

    void swap(DisjointSets& rhs) noexcept {
        std::swap(m_map, rhs.m_map);
        std::swap(m_find, rhs.m_find);
        std::swap(m_size, rhs.m_size);
    }

    bool make_set(T elem) {
        T root;
        if (m_find(m_map, elem, root)) {
            return false;
        }
        else {
            ++m_size;
            m_map[elem] = elem;
            return true;
        }
    }

    bool merge(T elem1, T elem2) {
        assert(elem1 != elem2);

        T root1;
        bool found1 = m_find(m_map, elem1, root1);
        T root2;
        bool found2 = m_find(m_map, elem2, root2);

        if (found1) {
            if (found2) {
                if (root1 == root2) {
                    return false;
                }
                else {
                    --m_size;
                    m_map[root2] = root1;
                }
            }
            else {
                m_map[elem2] = root1;
            }
        }
        else {
            if (found2) {
                m_map[elem1] = root2;
            }
            else {
                ++m_size;
                m_map[elem1] = m_map[elem2] = elem1;
            }
        }

        return true;
    }

    bool connected(T elem1, T elem2) const {
        T root1, root2;
        return (m_find(m_map, elem1, root1) && m_find(m_map, elem2, root2) && root1 == root2);
    }

    T root(T elem) const {
        T r;
        bool found = m_find(m_map, elem, r);
        assert(found);

        return r;
    }

    bool contain(T elem) const {
        T root;
        return (m_find(m_map, elem, root));
    }

    size_t size() const {
        return m_size;
    }

    size_t cardinality(T elem) const {
        T root;
        if (!m_find(m_map, elem, root)) {
            return 0;
        }

        size_t c = 0;
        for (const pair<T, T>& p : m_map) {
            T rootTmp;
            m_find(m_map, p.first, rootTmp);
            if (rootTmp == root) {
                ++c;
            }
        }

        return c;
    }

    bool sigleton(T elem) const {
        T root;
        if (!m_find(m_map, elem, root)) {
            return false;
        }

        size_t count = 0;
        for (const pair<T, T>& p : m_map) {
            T rootTmp;
            m_find(m_map, p.first, rootTmp);
            if (rootTmp == root) {
                if (1 < ++count) {
                    return false;
                }
            }
        }

        return true;
    }

    template<template<typename, typename...> class Container = std::vector, typename... Args>
    Container<T, Args...> set(T elem) const {
        Container<T, Args...> ret;

        T root;
        if (!m_find(m_map, elem, root)) {
            return ret;
        }

        for (const auto& p : m_map) {
            T rootTmp;
            m_find(m_map, p.first, rootTmp);
            if (rootTmp == root) {
                ret.insert(ret.end(), p.first);
            }
        }

        return ret;
    }

    template<template<typename, typename...> class Container = std::vector, typename... Args>
    Container<Container<T, Args...>, Args...> sets() const {
        std::map<T, Container<T, Args...>> ss;
        for (const auto& p : m_map) {
            T root;
            m_find(m_map, p.first, root);

            ss[root].insert(ss[root].end(), p.first);
        }

        Container<Container<T, Args...>, Args...> ret;
        for (std::pair<const T, Container<T, Args...>>& p : ss) {
            ret.insert(ret.end(), std::move(p.second));
        }

        return ret;
    }

protected:
    mutable Map m_map;
    Find m_find;
    size_t m_size;
};

namespace std {
    template<typename T, typename Map, typename Find>
    inline void swap(DisjointSets<T, Map, Find>& x, DisjointSets<T, Map, Find>& y) noexcept(noexcept(x.swap(y))) {
        x.swap(y);
    }
}

#endif

class Solution {
public:
    int removeStones_bfs(vector<vector<int>>& stones) {
        size_t n = stones.size();
        vector<vector<bool>> adjMtx(n, vector<bool>(n, false));
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = i + 1; j < n; ++j) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    adjMtx[i][j] = adjMtx[j][i] = true;
                }
            }
        }

        size_t dsSize = 0; // size of disjoint_sets
        vector<bool> visited(n, false);
        for (size_t root = 0; root < n; ++root) {
            if (visited[root]) {
                continue;
            }

            ++dsSize;

            queue<size_t> nodes;
            visited[root] = true;
            nodes.push(root);
            while (!nodes.empty()) {
                size_t i = nodes.front();
                nodes.pop();
                for (size_t j = 0; j < n; ++j) {
                    if (adjMtx[i][j] && !visited[j]) {
                        visited[j] = true;
                        nodes.push(j);
                    }
                }
            }
        }

        return n - dsSize;
    }

    int removeStones_UnionFind(vector<vector<int>>& stones) {
        //DisjointSets<unsigned short> ds;
        DisjointSets<unsigned short, SequenceWrapper<vector<unsigned short>>> ds;
        for (const auto& stone : stones) {
            ds.merge(stone[0], stone[1] + 10000);
        }

        return stones.size() - ds.size();
    }

    int removeStones(vector<vector<int>>& stones) {
        //return removeStones_bfs(stones);
        return removeStones_UnionFind(stones);
    }
};
