#include <vector>
#include <functional>
#include <initializer_list>

template<class T, class Container = std::vector<T>, class BinaryOperation = std::min<typename Container::value_type>>
class SegmentTree {
public:
    SegmentTree()
    
    explicit
    template<class InputIterator> // consider rename input iterator
    SegmentTree(InputIterator first, InputIterator last, const BinaryOperation& op = BinaryOperation())

    SegmentTree(std::initializer_list<T> list, const BinaryOperation& op = BinaryOperation())
    
    /*
    template<typename _Seq = _Sequence, typename _Requires = typename
	       enable_if<__and_<is_default_constructible<_Compare>,
				is_default_constructible<_Seq>>::value>::type>
	priority_queue()
	: c(), comp() { }

      explicit
      priority_queue(const _Compare& __x, const _Sequence& __s)
      : c(__s), comp(__x)
      { std::make_heap(c.begin(), c.end(), comp); }

      explicit
      priority_queue(const _Compare& __x, _Sequence&& __s = _Sequence())
      : c(std::move(__s)), comp(__x)
      { std::make_heap(c.begin(), c.end(), comp); }

      template<typename _Alloc, typename _Requires = _Uses<_Alloc>>
	explicit
	priority_queue(const _Alloc& __a)
	: c(__a), comp() { }

      template<typename _Alloc, typename _Requires = _Uses<_Alloc>>
	priority_queue(const _Compare& __x, const _Alloc& __a)
	: c(__a), comp(__x) { }

      // _GLIBCXX_RESOLVE_LIB_DEFECTS
      // 2537. Constructors [...] taking allocators should call make_heap
      template<typename _Alloc, typename _Requires = _Uses<_Alloc>>
	priority_queue(const _Compare& __x, const _Sequence& __c,
		       const _Alloc& __a)
	: c(__c, __a), comp(__x)
	{ std::make_heap(c.begin(), c.end(), comp); }

      template<typename _Alloc, typename _Requires = _Uses<_Alloc>>
	priority_queue(const _Compare& __x, _Sequence&& __c, const _Alloc& __a)
	: c(std::move(__c), __a), comp(__x)
	{ std::make_heap(c.begin(), c.end(), comp); }

      template<typename _Alloc, typename _Requires = _Uses<_Alloc>>
	priority_queue(const priority_queue& __q, const _Alloc& __a)
	: c(__q.c, __a), comp(__q.comp) { }

      template<typename _Alloc, typename _Requires = _Uses<_Alloc>>
	priority_queue(priority_queue&& __q, const _Alloc& __a)
	: c(std::move(__q.c), __a), comp(std::move(__q.comp)) { }
    */

    //range (1)
    void assign (InputIterator first, InputIterator last);
    //initializer list (3)
    
    void assign(std::initializer_list<T> l);



    bool empty() const;
    size_t size() const;
    void swap();
    const T& top() const;
    const T& query(size_t lo, size_t hi) const;
    void clear();
    void set(size_t index, const T& val);
    void swap(SegmentTree&)
    
    
    BinaryOperation op() const {
        return m_op;
    }
    
protected:
    void clear() {
        
    }
    
    void build();

    Container m_container;
    
    BinaryOperation m_op
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