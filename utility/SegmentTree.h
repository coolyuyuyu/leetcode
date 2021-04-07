#include <cassert>
#include <vector>
#include <functional>
#include <initializer_list>
#include <iterator>
#include <tuple>
#include <type_traits>


// https://github.com/gcc-mirror/gcc/blob/master/libstdc%2B%2B-v3/include/bits/stl_queue.h
template<typename T, typename Container = std::vector<T>, typename BinaryOperation = std::plus<T>>
class SegmentTree {
public:
    static_assert(std::is_same<T, typename Container::value_type>::value, "value_type must be the same as the underlying container");

    // __and_ needs update
    template<typename Cntr = Container, typename = typename enable_if<__and_<is_default_constructible<BinaryOperation>, is_default_constructible<Cntr>>::value>::type>
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
        : m_cntr()
        , m_op(op)
        , m_size(cntr.size())
        //: m_cntr(std::move(cntr)), m_op(op)
    {
        cout << "constructor:" << "move container123" << endl;
    }



    // --- range ---

    // check out is_default_constructible<BinaryOperation>
    template<typename InputIterator>
    explicit
    SegmentTree(InputIterator first, InputIterator last, const Container& cntr)
        : m_cntr()
        , m_op()
    {
        cout << "constructor:" << "range copy" << endl;
    }

    // check out is_default_constructible<BinaryOperation>
    template<typename InputIterator>
    explicit
    SegmentTree(InputIterator first, InputIterator last, Container&& cntr = Container())
        : m_cntr()
        , m_op()
        , m_size(std::distance(first, last)) {
        build(first);
        cout << "constructor:" << "range move" << endl;
    }

    template<typename InputIterator>
    explicit
    SegmentTree(InputIterator first, InputIterator last, const BinaryOperation& op, const Container& cntr)
        : m_cntr()
        , m_op(op)
    {
        cout << "constructor:" << "range op + copy" << endl;
    }

    template<typename InputIterator>
    explicit
    SegmentTree(InputIterator first, InputIterator last, const BinaryOperation& op, Container&& cntr = Container())
        : m_cntr()
        , m_op(op)
        , m_size(std::distance(first, last)) {
        build(first);
        cout << "constructor:" << "range op + move" << endl;
    }

    // --- initializer_list ---

    // check out is_default_constructible<BinaryOperation>
    explicit
    SegmentTree(std::initializer_list<T> l, const Container& cntr)
        : m_cntr()
        , m_op()
    {
        cout << "constructor:" << "initializer_list copy" << endl;
    }

    // check out is_default_constructible<BinaryOperation>
    explicit
    SegmentTree(std::initializer_list<T> l, Container&& cntr = Container())
        : m_cntr()
        , m_op()
        , m_size(std::distance(l.begin(), l.end()))
    {
        cout << "constructor:" << "initializer_list move" << endl;
        build(l.begin());
    }

    explicit
    SegmentTree(std::initializer_list<T> l, const BinaryOperation& op, const Container& cntr)
        : m_cntr()
        , m_op(op)
    {
        cout << "constructor:" << "initializer_list op + copy" << endl;
    }

    explicit
    SegmentTree(std::initializer_list<T> l, const BinaryOperation& op, Container&& cntr = Container())
        : m_cntr()
        , m_op(op)
        , m_size(std::distance(l.begin(), l.end()))
    {
        cout << "constructor:" << "initializer_list op + move" << endl;
        //build(l.begin());
    }

    template<typename InputIterator>
    void assign(InputIterator first, InputIterator last) {
        clear();

        m_size = std::distance(first, last);
        build(first);
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

    void set(size_t index, const T& val) {
        assert(index < size());
        
        // std::tuple<int, int, int>: <lo, hi, index, visited>
        std::stack<std::tuple<size_t, size_t, size_t, bool>> stk({{0, size() - 1, 0, false}});
        while (!stk.empty()) {
            size_t l = std::get<0>(stk.top());
            size_t h = std::get<1>(stk.top());
            size_t i = std::get<2>(stk.top());
            bool visited = std::get<3>(stk.top());
            stk.pop();
            
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
                    stk.emplace(l, h, i, true);
                    stk.emplace(l, m, lftChild(i), false);
                    stk.emplace(m + 1, h, rhtChild(i), false);
                }
            }
        }
    }

    T query(size_t lo, size_t hi) const {
        assert(lo <= hi && hi < size());

        T val = T();

        std::stack<tuple<size_t, size_t, size_t>> stk({{0, size() - 1, 0}});
        while (!stk.empty()) {
            size_t l = std::get<0>(stk.top());
            size_t h = std::get<1>(stk.top());
            size_t i = std::get<2>(stk.top());
            stk.pop();

            if (h < lo || hi < l) {
                continue;
            }

            if (lo <= l && h <= hi) {
                val = m_op(val, m_cntr[i]);
            }
            else {
                size_t m = l + (h - l) / 2;
                stk.emplace(l, m, lftChild(i));
                stk.emplace(m + 1, h, rhtChild(i));
            }
        }

        return val;
    }

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

        return m_cntr[index];
    }

//protected:
public:
    template<typename InputIterator>
    void build(InputIterator itr) {
        if (empty()) {
            return;
        }

        // TODO: Trade off, may cost too much memory.
        size_t height = static_cast<size_t>(ceil(log2(static_cast<double>(size())))) + 1;
        size_t capacity = (size_t(2) << (height - 1)) - 1;
        m_cntr.resize(capacity);

        // std::tuple<int, int, int>: <lo, hi, index, visited>
        std::stack<std::tuple<size_t, size_t, size_t, bool>> stk({{0, size() - 1, 0, false}});
        while (!stk.empty()) {
            size_t l = std::get<0>(stk.top());
            size_t h = std::get<1>(stk.top());
            size_t i = std::get<2>(stk.top());
            bool visited = std::get<3>(stk.top());
            stk.pop();

            if (l == h) {
                m_cntr[i] = *std::next(itr, l);
                continue;
            }

            if (visited) {
                m_cntr[i] = m_op(m_cntr[lftChild(i)], m_cntr[rhtChild(i)]);
            }
            else {
                size_t m = l + (h - l) / 2;
                stk.emplace(l, h, i, true);
                stk.emplace(l, m, lftChild(i), false);
                stk.emplace(m + 1, h, rhtChild(i), false);
            }
        }
    }

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






int main() {
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
