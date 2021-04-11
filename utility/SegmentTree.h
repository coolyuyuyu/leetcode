#ifndef __SEGMENT_TREE_H__0B7E3C64_E02D_472F_859B_A31C85FBD4E5
#define __SEGMENT_TREE_H__0B7E3C64_E02D_472F_859B_A31C85FBD4E5

#include <algorithm>
#include <cassert>
#include <functional>
#include <initializer_list>
#include <iterator>
#include <stdexcept>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>

/*
// TODO:
    1. Investigate why iterative QUERY implementation slow
    2. refactor: extract get index funtion. [] and set
*/

#define SEGMENT_TREE_ITERATIVE_IMPL

//#define SEGMENT_TREE_ITERATIVE_BUILD_IMPL
//#define SEGMENT_TREE_ITERATIVE_SET_IMPL
//#define SEGMENT_TREE_ITERATIVE_QUERY_IMPL

#ifdef SEGMENT_TREE_ITERATIVE_IMPL
    #define SEGMENT_TREE_ITERATIVE_BUILD_IMPL
    #define SEGMENT_TREE_ITERATIVE_SET_IMPL
    #define SEGMENT_TREE_ITERATIVE_QUERY_IMPL
#endif

template<typename T, typename Container = std::vector<T>, typename BinaryOperation = std::plus<typename Container::value_type>>
class SegmentTree {
public:
    static_assert(std::is_same<T, typename Container::value_type>::value, "value_type must be the same as the underlying container");

    template<typename = typename std::enable_if<std::is_default_constructible<Container>::value && std::is_default_constructible<BinaryOperation>::value>::type>
    SegmentTree()
        : m_cntr()
        , m_op()
        , m_size(0) {
    }

    explicit SegmentTree(const BinaryOperation& op, const Container& cntr)
        : m_cntr()
        , m_op(op)
        , m_size(cntr.size()) {
        build(cntr.begin(), cntr.end());
    }

    explicit SegmentTree(const BinaryOperation& op, Container&& cntr = Container())
        : m_cntr()
        , m_op(op)
        , m_size(cntr.size()) {
        build(std::make_move_iterator(cntr.begin()), std::make_move_iterator(cntr.end()));
    }

    template<typename InputIterator>
    explicit SegmentTree(InputIterator first, InputIterator last, const Container& cntr)
        : m_cntr()
        , m_op()
        , m_size(cntr.size()+ std::distance(first, last)) {
        build(cntr.begin(), cntr.end(), first, last);
    }

    template<typename InputIterator>
    explicit SegmentTree(InputIterator first, InputIterator last, Container&& cntr = Container())
        : m_cntr()
        , m_op()
        , m_size(cntr.size() + std::distance(first, last)) {
        build(std::make_move_iterator(cntr.begin()), std::make_move_iterator(cntr.end()), first, last);
    }

    template<typename InputIterator>
    explicit SegmentTree(InputIterator first, InputIterator last, const BinaryOperation& op, const Container& cntr)
        : m_cntr()
        , m_op(op)
        , m_size(cntr.size() + std::distance(first, last)) {
        build(cntr.begin(), cntr.end(), first, last);
    }

    template<typename InputIterator>
    explicit SegmentTree(InputIterator first, InputIterator last, const BinaryOperation& op, Container&& cntr = Container())
        : m_cntr()
        , m_op(op)
        , m_size(cntr.size() + std::distance(first, last)) {
        build(std::make_move_iterator(cntr.begin()), std::make_move_iterator(cntr.end()), first, last);
    }

    explicit SegmentTree(std::initializer_list<T> l, const Container& cntr)
        : m_cntr()
        , m_op()
        , m_size(cntr.size() + l.size()) {
        build(cntr.begin(), cntr.end(), l.begin(), l.end());
    }

    explicit SegmentTree(std::initializer_list<T> l, Container&& cntr = Container())
        : m_cntr()
        , m_op()
        , m_size(cntr.size() + l.size()) {
        build(std::make_move_iterator(cntr.begin()), std::make_move_iterator(cntr.end()), l.begin(), l.end());
    }

    explicit SegmentTree(std::initializer_list<T> l, const BinaryOperation& op, const Container& cntr)
        : m_cntr()
        , m_op(op)
        , m_size(cntr.size() + l.size()) {
        build(cntr.begin(), cntr.end(), l.begin(), l.end());
    }

    explicit SegmentTree(std::initializer_list<T> l, const BinaryOperation& op, Container&& cntr = Container())
        : m_cntr()
        , m_op(op)
        , m_size(cntr.size() + l.size()) {
        build(std::make_move_iterator(cntr.begin()), std::make_move_iterator(cntr.end()), l.begin(), l.end());
    }

    template<typename InputIterator>
    void assign(InputIterator first, InputIterator last) {
        clear();

        m_size = std::distance(first, last);
        build(first, last);
    }

    void assign(std::initializer_list<T> l) {
        assign(l.begin(), l.end());
    }

    inline bool empty() const {
        return (m_size == 0);
    }

    inline size_t size() const {
        return m_size;
    }

    void swap(SegmentTree& rhs) {
        std::swap(m_cntr, rhs.m_cntr);
        std::swap(m_op, rhs.m_op);
        std::swap(m_size, rhs.m_size);
    }

    const T& top() const {
        assert(!empty());

        return m_cntr[0];
    }

    void clear() {
        m_cntr.clear();
        m_size = 0;
    }

    BinaryOperation op() const {
        return m_op;
    }

#ifdef SEGMENT_TREE_ITERATIVE_SET_IMPL
    void set(size_t index, const T& val) {
        if (size() <= index) {
            throw std::out_of_range("invalid subscript");
        }

        size_t l = 0, h = size() - 1, i = 0;
        while (l < h) {
            size_t m = l + (h - l) / 2;
            if (index <= m) {
                h = m;
                i = lftChild(i);
            }
            else {
                l = m + 1;
                i = rhtChild(i);
            }
        }
        m_cntr[i] = val;

        while (!root(i)) {
            size_t p = parent(i);
            m_cntr[p] = m_op(m_cntr[lftChild(p)], m_cntr[rhtChild(p)]);
            i = p;
        }
    }

#else
    void set(size_t index, const T& val) {
        if (size() <= index) {
            throw std::out_of_range("invalid subscript");
        }

        set(0, size() - 1, 0, index, val);
    }

    void set(size_t l, size_t h, size_t i, size_t index, const T& val) {
        assert(l <= h);

        if (index < l || h < index) {
            return;
        }

        if (l == h) {
            assert(index == l);
            m_cntr[i] = val;
        }
        else {
            size_t m = l + (h - l) / 2;
            size_t lft = lftChild(i), rht = rhtChild(i);
            set(l, m, lft, index, val);
            set(m + 1, h, rht, index, val);
            m_cntr[i] = m_op(m_cntr[lft], m_cntr[rht]);
        }
    }
#endif

#ifdef SEGMENT_TREE_ITERATIVE_QUERY_IMPL
    T query(size_t lo, size_t hi) const {
        if (hi < lo || size() < hi) {
            throw std::out_of_range("invalid range");
        }

        if (lo == hi) {
            return (*this)[lo];
        }

        std::unique_ptr<T> pVal;
        std::vector<tuple<size_t, size_t, size_t>> stk({{0, size() - 1, 0}});
        while (!stk.empty()) {
            size_t l, h, i;
            std::tie(l, h, i) = stk.back();
            stk.pop_back();

            if (h < lo || hi < l) {
                continue;
            }

            if (lo <= l && h <= hi) {
                if (pVal) {
                    *pVal = m_op(*pVal, m_cntr[i]);
                }
                else {
                    pVal = make_unique<T>(m_cntr[i]);
                }
            }
            else {
                size_t m = l + (h - l) / 2;
                stk.emplace_back(m + 1, h, rhtChild(i));
                stk.emplace_back(l, m, lftChild(i));
            }
        }

        return *pVal;
    }

#else
    T query(size_t lo, size_t hi) const {
        if (hi < lo || size() < hi) {
            throw std::out_of_range("invalid range");
        }

        if (lo == hi) {
            return (*this)[lo];
        }
        else {
            return query(0, size() - 1, 0, lo, hi).first;
        }
    }

    std::pair<T, bool> query(size_t l, size_t h, size_t i, size_t lo, size_t hi) const {
        assert(l <= h);

        if (h < lo || hi < l) {
            std::pair<T, bool> p;
            p.second = false;
            return p;
        }

        if (lo <= l && h <= hi) {
            return {m_cntr[i], true};
        }
        else {
            size_t m = l + (h - l) / 2;
            std::pair<T, bool> lft = query(l, m, lftChild(i), lo, hi);
            std::pair<T, bool> rht = query(m + 1, h, rhtChild(i), lo, hi);
            if (lft.second && rht.second) {
                return {m_op(lft.first, rht.first), true};
            }
            else {
                assert(lft.second || rht.second);
                return (lft.second ? lft : rht);
            }
        }
    }
#endif

    const T& operator[](size_t index) const {
        assert(index < size());

        size_t l = 0, h = size() - 1, i = 0;
        while (l < h) {
            size_t m = l + (h - l) / 2;
            if (index <= m) {
                h = m;
                i = lftChild(i);
            }
            else {
                l = m + 1;
                i = rhtChild(i);
            }
        }

        return m_cntr[i];
    }

    const T& at(size_t index) const {
        if (size() <= index) {
            throw std::out_of_range("invalid subscript");
        }

        return (*this)[index];
    }

protected:
    inline bool root(size_t i) const {
        return (i == 0);
    }

    inline size_t parent(size_t i) const {
        assert(!root(i));
        return (i - 1) / 2;
    }

    inline size_t lftChild(size_t i) const {
        return (i * 2 + 1);
    }

    inline size_t rhtChild(size_t i) const {
        return (i * 2 + 2);
    }

#ifdef SEGMENT_TREE_ITERATIVE_BUILD_IMPL
    template<typename InputIterator1, typename InputIterator2 = typename Container::iterator>
    void build(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 = InputIterator2(), InputIterator2 last2 = InputIterator2()) {
        if (empty()) {
            return;
        }

        // std::tuple<int, int, int>: <lo, hi, index, visited>
        std::vector<std::tuple<size_t, size_t, size_t, bool>> stk({{0, size() - 1, 0, false}});
        while (!stk.empty()) {
            size_t l, h, i; bool visited;
            std::tie(l, h, i, visited) = stk.back();
            stk.pop_back();

            if (l == h) {
                if (m_cntr.size() <= i) {
                    m_cntr.resize(i + 1);
                }

                if (first1 != last1) {
                    m_cntr[i] = *first1++;
                }
                else {
                    m_cntr[i] = *first2++;
                }

                if (l == (size() - 1)) {
                    m_cntr.shrink_to_fit();
                }

                continue;
            }

            if (visited) {
                m_cntr[i] = m_op(m_cntr[lftChild(i)], m_cntr[rhtChild(i)]);
            }
            else {
                size_t m = l + (h - l) / 2;
                stk.emplace_back(l, h, i, true);
                stk.emplace_back(m + 1, h, rhtChild(i), false);
                stk.emplace_back(l, m, lftChild(i), false);
            }
        }
    }

#else
    template<typename InputIterator1, typename InputIterator2 = typename Container::iterator>
    void build(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 = InputIterator2(), InputIterator2 last2 = InputIterator2()) {
        if (!empty()) {
            build(0, m_size - 1, 0, first1, last1, first2, last2);
        }
    }

    template<typename InputIterator1, typename InputIterator2>
    void build(size_t l, size_t h, size_t i, InputIterator1& first1, InputIterator1 last1, InputIterator2& first2, InputIterator2 last2) {
        assert(l <= h);

        if (l == h) {
            if (m_cntr.size() <= i) {
                m_cntr.resize(i + 1);
            }

            if (first1 != last1) {
                m_cntr[i] = *first1++;
            }
            else {
                m_cntr[i] = *first2++;
            }

            if (l == (size() - 1)) {
                m_cntr.shrink_to_fit();
            }

            return;
        }

        size_t m = l + (h - l) / 2;
        size_t lft = lftChild(i), rht = rhtChild(i);
        build(l, m, lft, first1, last1, first2, last2);
        build(m + 1, h, rht, first1, last1, first2, last2);
        m_cntr[i] = m_op(m_cntr[lft], m_cntr[rht]);
    }
#endif

    Container m_cntr;
    BinaryOperation m_op;
    size_t m_size;
};

#endif
