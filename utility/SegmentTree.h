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
    }

    explicit
    SegmentTree(const BinaryOperation& op, const Container& cntr)
        : m_cntr(cntr)
        , m_op(op)
        , m_size(cntr.size())
    {}

    explicit
    SegmentTree(const BinaryOperation& op, Container&& cntr = Container())
        : m_cntr()
        , m_op(op)
        , m_size(cntr.size())
        //: m_cntr(std::move(cntr)), m_op(op)
    {}

    template<typename InputIterator>
    SegmentTree(InputIterator first, InputIterator last, const BinaryOperation& op, const Container& cntr)
        : m_cntr(cntr)
        , m_op(op)
    {
    }

    template<typename InputIterator>
    SegmentTree(InputIterator first, InputIterator last, const BinaryOperation& op = BinaryOperation(), Container&& cntr = Container())
        : m_cntr()
        , m_op(op)
        , m_size(cntr.size() + std::distance(first, last))
        //: m_cntr(std::move(cntr)), m_op(op)
    {
    //c.insert(c.end(), __first, __last);
    //std::make_heap(c.begin(), c.end(), comp);
    }

    //range (1)
    template<typename InputIterator>
    void assign(InputIterator first, InputIterator last) {
        clear();
        m_size = std::distance(first, last);
        //build(first, last, );
    }

    //void assign(std::initializer_list<T> l);


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
        typename iterator_traits<InputIterator>::difference_type size = std::distance(first, last);
    }

    Container m_cntr;
    BinaryOperation m_op;
    size_t m_size;
};


/*
priority_queue
priority_queue::priority_queue
member functions:
priority_queue::emplace
priority_queue::empty
priority_queue::pop
priority_queue::push
priority_queue::size
priority_queue::swap
priority_queue::top
non-member overloads:
swap (priority_queue)
non-member specializations:
uses_allocator<priority_queue>
*/
};