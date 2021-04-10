#ifndef __SEGMENT_TREE_H__3B3F2F06_799B_4581_B7A4_4C01B9324782
#define __SEGMENT_TREE_H__3B3F2F06_799B_4581_B7A4_4C01B9324782

#include <algorithm>
#include <cassert>
#include <vector>
#include <functional>
#include <initializer_list>
#include <iterator>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>


// TODO:
/*
    1. build may or not prepare all size
    1. build may or may not shrink to fit at end
    2. implement move for optional container
    3. support at . exception throw
*/

#ifdef SEGMENT_TREE_ITERATIVE_IMP
    #define SEGMENT_TREE_ITERATIVE_BUILD_IMP
    #define SEGMENT_TREE_ITERATIVE_SET_IMP
    #define SEGMENT_TREE_ITERATIVE_QUERY_IMP
#endif

// Recursive set:   1000ms->600ms, 400MB->217MB
// Recursive query: 1000ms->800ms, 400MB->385MB
// both Recursive:  1000ms->400ms, 400MB->155MB
//#define SEGMENT_TREE_ITERATIVE_BUILD_IMP
//#define SEGMENT_TREE_ITERATIVE_SET_IMP
//#define SEGMENT_TREE_ITERATIVE_QUERY_IMP


// https://github.com/gcc-mirror/gcc/blob/master/libstdc%2B%2B-v3/include/bits/stl_queue.h
template<typename T, typename Container = std::vector<T>, typename BinaryOperation = std::plus<T>>
class SegmentTree {
public:
    static_assert(std::is_same<T, typename Container::value_type>::value, "value_type must be the same as the underlying container");
    
    SegmentTree() = default;
    SegmentTree(SegmentTree&&) noexcept = default;
    

    // __and_ needs update
    template<typename Cntr = Container, typename = typename std::enable_if<__and_<std::is_default_constructible<BinaryOperation>, std::is_default_constructible<Cntr>>::value>::type>
    SegmentTree()
        : m_cntr()
        , m_op()
        , m_size(0) {
        cout << "constructor: " << "default" << endl;
    }

    explicit
    SegmentTree(const BinaryOperation& op, const Container& cntr)
        : m_cntr(cntr)
        , m_op(op)
        , m_size(cntr.size())
    {
        cout << "constructor: " << "copy container" << endl;
    }

    explicit
    SegmentTree(const BinaryOperation& op, Container&& cntr = Container())
        : m_cntr(std::move(cntr))
        , m_op(op)
        , m_size(cntr.size()) {
        cout << "constructor:" << "move container123" << endl;
    }



    // --- range ---

    // check out is_default_constructible<BinaryOperation>
    template<typename InputIterator>
    explicit
    SegmentTree(InputIterator first, InputIterator last, const Container& cntr)
        : m_cntr(cntr)
        , m_op()
        , m_size(cntr.size()+ std::distance(first, last))
    {
        cout << "constructor:" << "range copy" << endl;
        build(first, last);
    }

    // check out is_default_constructible<BinaryOperation>
    template<typename InputIterator>
    explicit
    SegmentTree(InputIterator first, InputIterator last, Container&& cntr = Container())
        : m_cntr(std::move(cntr))
        , m_op()
        , m_size(m_cntr.size() + std::distance(first, last)) {
        cout << "constructor:" << "range move" << endl;
        cout << "recursive overall template size:" << sizeof(T) * m_cntr.capacity() << endl;
        build(first, last);
    }

    template<typename InputIterator>
    explicit
    SegmentTree(InputIterator first, InputIterator last, const BinaryOperation& op, const Container& cntr)
        : m_cntr(cntr)
        , m_op(op)
        , m_size(m_cntr.size() + std::distance(first, last))
    {
        cout << "constructor:" << "range op + copy" << endl;
        build(first, last);
    }

    template<typename InputIterator>
    explicit
    SegmentTree(InputIterator first, InputIterator last, const BinaryOperation& op, Container&& cntr = Container())
        : m_cntr(std::move(cntr))
        , m_op(op)
        , m_size(m_cntr.size() + std::distance(first, last)) {
        cout << "constructor:" << "range op + move" << endl;
        build(first, last);
    }

    // --- initializer_list ---

    // check out is_default_constructible<BinaryOperation>
    explicit
    SegmentTree(std::initializer_list<T> l, const Container& cntr)
        : m_cntr(cntr)
        , m_op()
        , m_size(m_cntr.size() + l.size()) {
        cout << "constructor:" << "initializer_list copy" << endl;
        build(l.begin(), l.end());
    }

    // check out is_default_constructible<BinaryOperation>
    explicit
    SegmentTree(std::initializer_list<T> l, Container&& cntr = Container())
        : m_cntr(std::move(cntr))
        , m_op()
        , m_size(m_cntr.size() + l.size()) {
        cout << "constructor:" << "initializer_list move" << endl;
        build(l.begin(), l.end());

        cout << "cap:" << m_cntr.capacity() << ", size: " << m_cntr.size() << endl;
    }

    explicit
    SegmentTree(std::initializer_list<T> l, const BinaryOperation& op, const Container& cntr)
        : m_cntr(cntr)
        , m_op(op)
        , m_size(m_cntr.size() + l.size()) {
        cout << "constructor:" << "initializer_list op + copy" << endl;
        build(l.begin(), l.end());
    }

    explicit
    SegmentTree(std::initializer_list<T> l, const BinaryOperation& op, Container&& cntr = Container())
        : m_cntr(ste::move(cntr))
        , m_op(op)
        , m_size(m_cntr.size() + l.size()) {
        cout << "constructor:" << "initializer_list op + move" << endl;
        build(l.begin(), l.end());
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

    bool empty() const {
        return (m_size == 0);
    }

    size_t size() const {
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

#ifdef SEGMENT_TREE_ITERATIVE_SET_IMP
    void set(size_t index, const T& val) {
        assert(index < size());

        // std::tuple<int, int, int>: <lo, hi, index, visited>
        std::vector<std::tuple<size_t, size_t, size_t, bool>> stk({{0, size() - 1, 0, false}});
        while (!stk.empty()) {
            size_t l, h, i; bool visited;
            std::tie(l, h, i, visited) = stk.back();
            stk.pop_back();

            if (index < l || h < index) {
                continue;
            }

            if (l == h) {
                assert(index == l);
                m_cntr[i] = val;
            }
            else {
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
    }

#else
    void set(size_t index, const T& val) {
        assert(index < size());

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

#ifdef SEGMENT_TREE_ITERATIVE_QUERY_IMP
    T query(size_t lo, size_t hi) const {
        assert(lo <= hi && hi < size());

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
        assert(lo <= hi && hi < size());

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
            return { m_cntr[i], true };
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
            // throw exception
        }

        return (*this)[index];
    }

protected:
#ifdef SEGMENT_TREE_ITERATIVE_BUILD_IMP
    template<typename InputIterator>
    void build(InputIterator first, InputIterator last) {
        if (empty()) {
            return;
        }

        // TODO: Trade off, may cost too much memory.
        //size_t height = static_cast<size_t>(ceil(log2(static_cast<double>(size())))) + 1;
        //size_t capacity = (size_t(2) << (height - 1)) - 1;
        //m_cntr.resize(capacity);

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
                m_cntr[i] = *first++;
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
    template<typename InputIterator>
    void build(InputIterator first, InputIterator last) {
        if (!empty()) {
            build(0, m_size - 1, 0, first, last);
        }
    }

    template<typename InputIterator>
    void build(size_t l, size_t h, size_t i, InputIterator& first, InputIterator last) {
        assert(l <= h);

        if (l == h) {
            if (m_cntr.size() <= i) {
                m_cntr.resize(i + 1);
            }
            m_cntr[i] = *first++;
            if (l == (size() - 1)) {
                m_cntr.shrink_to_fit();
            }

            return;
        }

        size_t m = l + (h - l) / 2;
        size_t lft = lftChild(i), rht = rhtChild(i);
        build(l, m, lft, first, last);
        build(m + 1, h, rht, first, last);
        m_cntr[i] = m_op(m_cntr[lft], m_cntr[rht]);
    }
#endif

    Container m_cntr;
    BinaryOperation m_op;
    size_t m_size;

private:
    inline size_t lftChild(size_t i) const {
        return (i * 2 + 1);
    }

    inline size_t rhtChild(size_t i) const {
        return (i * 2 + 2);
    }
};

#endif

int main() {
    auto comp = [](int a, int b) -> int {
        return std::max<int>(a, b);
    };
    SegmentTree<int, vector<int>, decltype(comp)> sstt({ -1,-2,-3,-4,-5, -6 }, comp);
    
    
    vector<int> vv = {-2,0,3,-5,2,-1};
    SegmentTree<int> stst(vv.begin(), vv.end());
    cout << stst.query(0, 2) << endl;
    cout << stst.query(2, 5) << endl;
    cout << stst.query(0, 5) << endl;
    //return 0;

    /*
    Range"]
[[[-2,0,3,-5,2,-1]],[0,2],[2,5],[0,5]]
    */


    auto bop = [](int a, int b) -> int {
        return a + b;
    };

    cout << "---initializer_list---" << endl;
    SegmentTree<int> st_i_default({1,2,3}, vv);
    SegmentTree<int> st_i_move0({1,2,3});
    SegmentTree<int> st_i_move1({1,2,3}, std::move(vv));

    SegmentTree<int, vector<int>, decltype(bop)> st_i_2({1,2,3}, bop);
    SegmentTree<int, vector<int>, decltype(bop)> st_i_3({1,2,3}, bop, vv);
    SegmentTree<int, vector<int>, decltype(bop)> st_i_4({1,2,3}, bop, std::move(vv));
    cout << "---initializer_list---" << endl;
    //SegmentTree<int> st_i_2({1,2,3}, vv);

    cout << "--" << endl;
    SegmentTree<int, vector<int>, decltype(bop)> st3(bop);
    cout << "--" << endl;
    std::cout << "Hello World123!\n";

    SegmentTree<int> sstt({0,1,2,3,4,5});
    /*
    for (size_t i = 0; i < sstt.m_cntr.size(); ++i) {
        cout << "Internal[" << i << "]: " << sstt.m_cntr[i] << endl;
    }


    for (size_t i = 0; i < 6; ++i) {
        cout << "External[" << i << "]: " << sstt[i] << endl;
    }
    */

    cout << "top: " << sstt.top() << endl;

    //cout << "query[3,4]: " << sstt.query(3, 4) << endl;
    cout << "query[0,3]: " << sstt.query(0, 3) << endl;
    //return 0;
  //  return 1;

    sstt.set(1, 100);
    for (size_t i = 0; i < 6; ++i) {
        for (size_t j = i; j < 6; ++j) {
            cout << "query[" << i << "," << j << "]: " << sstt.query(i, j) << endl;
        }
    }

    cout << sstt.op()(111,999) << endl;
}
