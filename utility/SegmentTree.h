#include <cassert>
#include <vector>
#include <functional>
#include <initializer_list>
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
    {
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
    {
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
    {
        cout << "constructor:" << "initializer_list move" << endl;
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
    {
        cout << "constructor:" << "initializer_list op + move" << endl;
    }
    
    template<typename InputIterator>
    void assign(InputIterator first, InputIterator last) {
        clear();
        m_size = std::distance(first, last);
        //build(first, last, );
    }

    void assign(std::initializer_list<T> l) {
        clear();
        //m_size = std::distance(first, last);
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
        return m_cntr.front();
    }

    //const T& query(size_t lo, size_t hi) const;

    void clear() {
        m_cntr.clear();
    }

    //void set(size_t index, const T& val);


    BinaryOperation op() const {
        return m_op;
    }


    void update(size_t i, const T& val) {
        //update(0, m_size - 1, 0, i, val);
    }

    T query(size_t lo, size_t hi) const {
        return T();
        //return query(0, m_size - 1, 0, lo , hi);
    }

    const T& operator[](size_t i) const {
        return m_cntr.front();
    }

protected:
    template<typename InputIterator>
    void build(InputIterator first, InputIterator last) {
        if (!empty()) {
            m_cntr.resize(m_size - 1);
            
            
            size_t minIndex = std::numeric_limits<size_t>::max()
            buildTopDown(0, size() - 1, 0, minIndex);
            
            
            build();
        }
        typename iterator_traits<InputIterator>::difference_type size = std::distance(first, last);
    }

    void build() {
        assert(!empty());

        std::stack<pair<std::tuple<size_t, size_t, size_t>, bool>> stk;
        stk.emplace({{0, size() - 1, 0}, false});
        while (!stk.empty()) {
            size_t lo = std::get<0>(stk.top().first);
            size_t hi = std::get<1>(stk.top().first);
            size_t index = std::get<2>(stk.top().first);
            bool visited = stk.top().second;
            stk.pop();

            if (lo == hi) {
                continue;
            }

            if (visited) {
                m_cntr[index] = m_op(m_cntr[lftChildIndex(index)], m_cntr[rhtChildIndex(index)]);
            }
            else {
                size_t mid = lo + (hi - lo) / 2;
                stk.emplace(lo, mid, lftChildIndex(index), false);
                stk.emplace(mid + 1, hi, rhtChildIndex(index), false);
                stk.emplace(lo, hi, index, true);
            }
        }
    }

    Container m_cntr;
    BinaryOperation m_op;
    size_t m_size;

private:
    inline size_t lftChildIndex(size_t index) {
        return (index * 2 + 1);
    }

    inline size_t rhtChildIndex(size_t index) {
        return (index * 2 + 2);
    }
};




/*
class RangeSumSegmentTreeByHeap : public RangeSumStrategy {
public:
    RangeSumSegmentTreeByHeap(vector<int>& nums)
        : m_size(nums.size()) {
        if (0 < m_size) {
            build(0, m_size - 1, 0, nums);
        }
    }

    void update(size_t i, int val) {
        update(0, m_size - 1, 0, i, val);
    }

    int sum(size_t lo, size_t hi) const {
        return query(0, m_size - 1, 0, lo , hi);
    }

private:
    inline size_t lftChildIndex(size_t parent) const {
        return parent * 2 + 1;
    }

    inline size_t rhtChildIndex(size_t parent) const {
        return parent * 2 + 2;
    }

    void build(size_t lo, size_t hi, size_t parent, const vector<int>& nums) {
        assert(lo <= hi);

        if (lo == hi) {
            if (m_sums.size() <= parent) {
                m_sums.resize(parent + 1);
            }
            m_sums[parent] = nums[lo];
            return;
        }

        size_t mid = lo + (hi - lo) / 2;
        size_t lftChild = lftChildIndex(parent), rhtChild = rhtChildIndex(parent);
        build(lo, mid, lftChild, nums);
        build(mid + 1, hi, rhtChild, nums);
        m_sums[parent] = m_sums[lftChild] + m_sums[rhtChild];
    }

    void update(size_t lo, size_t hi, size_t parent, size_t i, int val) {
        assert(lo <= hi);

        if (i < lo || hi < i) {
            return;
        }

        if (lo == hi) {
            assert(i == lo);
            m_sums[parent] = val;
        }
        else {
            size_t mid = lo + (hi - lo) / 2;
            size_t lftChild = lftChildIndex(parent), rhtChild = rhtChildIndex(parent);
            update(lo, mid, lftChild, i, val);
            update(mid + 1, hi, rhtChild, i, val);
            m_sums[parent] = m_sums[lftChild] + m_sums[rhtChild];
        }
    }

    int query(size_t lo, size_t hi, size_t parent, size_t i, size_t j) const {
        assert(lo <= hi);

        if (j < lo || hi < i) {
            return 0;
        }

        if (i <= lo && hi <= j) {
            return m_sums[parent];
        }
        else {
            size_t mid = lo + (hi - lo) / 2;
            return query(lo, mid, lftChildIndex(parent), i, j) + query(mid + 1, hi, rhtChildIndex(parent), i, j);
        }
    }

    size_t m_size;
    vector<int> m_sums;
};
*/


int main() {
    vector<int> vv;


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
}
