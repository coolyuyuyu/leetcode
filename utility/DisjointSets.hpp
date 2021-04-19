#ifndef __DISJOINT_SETS_HPP__493A883A_6A4F_4328_8CB1_58CB15279742
#define __DISJOINT_SETS_HPP__493A883A_6A4F_4328_8CB1_58CB15279742

#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <set>
#include <map>
#include <type_traits>
#include <utility>
#include <vector>

template <typename Map>
struct FindNoCompress {
    bool operator()(Map& map, typename Map::key_type elem, typename Map::key_type& root) const {
        typename Map::iterator itr = map.find(elem);
        if (itr == map.end()) {
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
        typename Map::iterator itr = map.find(elem);
        if (itr == map.end()) {
            return false;
        }
        else {
            root = itr->second;
            if (root == elem) {
                return true;
            }

            std::vector<Map::key_type> candidates;
            while (true) {
                itr = map.find(root);
                assert(itr != map.end());

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

template<typename T, typename Map = std::map<T, T>, typename Find = FindFullCompress<Map>, typename = typename std::enable_if<std::is_integral<T>::value, T>::type>
class DisjointSets {
public:
    typedef T value_type;
    typedef Map map_type;

    template<typename T1, typename Map1, typename Find1>
    friend bool operator==(const DisjointSets& x, const DisjointSets<T1, Map1, Find1>& y) {
        return (x.size() == y.size() && x.sets<std::set>() == y.sets<std::set>());
    }

    template<typename T1, typename Map1, typename Find1>
    friend bool operator!=(const DisjointSets& x, const DisjointSets<T1, Map1, Find1>& y) {
        return !(x == y);
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

        for (const std::pair<const T, T>& p : m_map) {
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
        for (const std::pair<const T, T>& p : m_map) {
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
