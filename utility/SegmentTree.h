#include <vector>
#include <functional>
#include <initializer_list>
#include <type_traits>


// https://github.com/gcc-mirror/gcc/blob/master/libstdc%2B%2B-v3/include/bits/stl_queue.h
template<typename T, typename Container = std::vector<T>, typename BinaryOperation = std::plus<typename Container::value_type>>
class SegmentTree {
public:
    static_assert(std::is_same<T, typename Container::value_type>::value, "value_type must be the same as the underlying container");

    // __and_ needs update
    template<typename Cntr = Container, typename = typename enable_if<__and_<is_default_constructible<BinaryOperation>, is_default_constructible<Cntr>>::value>::type>
    SegmentTree()
        : m_cntr()
        , m_op() {
    }

    explicit
    SegmentTree(const BinaryOperation& op, const Container& cntr)
        : m_cntr(cntr)
        , m_op(op)
    {}

    explicit
    SegmentTree(const BinaryOperation& op, Container&& cntr = Container())
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
        //: m_cntr(std::move(cntr)), m_op(op)
    {
    //c.insert(c.end(), __first, __last);
    //std::make_heap(c.begin(), c.end(), comp);
    }

    //range (1)
    template<typename InputIterator>
    void assign(InputIterator first, InputIterator last) {
        build(first, last, );
    }
    //initializer list (3)

    //void assign(std::initializer_list<T> l);


    //bool empty() const;
    //size_t size() const;
    //void swap();
    //const T& top() const;
    //const T& query(size_t lo, size_t hi) const;
    
    void clear() {
        m_cntr.clear()
    }
    
    //void set(size_t index, const T& val);
    //void swap(SegmentTree&)
    


    BinaryOperation op() const {
        return m_op;
    }

protected:
    
    template<typename InputIterator>
    void build(InputIterator first, InputIterator last) {
        typename iterator_traits<InputIterator>::difference_type size = std::distance(first, last);
    }

    Container m_cntr;
    BinaryOperation m_op;
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