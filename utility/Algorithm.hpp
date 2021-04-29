#ifndef __ALGORITHM_HPP__D3CA27F7_E64B_410C_8018_06F09F77DE96
#define __ALGORITHM_HPP__D3CA27F7_E64B_410C_8018_06F09F77DE96


#include <functional>
#include <iterator>


template<typename InputIterator, typename Compare = std::less<typename std::iterator_traits<InputIterator>::value_type>>
typename std::iterator_traits<InputIterator>::value_type findSmallest_Heap(InputIterator first, InputIterator last, size_t k, Compare comp = Compare()) {
    priority_queue<typename std::iterator_traits<InputIterator>::value_type> pq;
    for (; first != last; ++first) {
        if (pq.size() <= k) {
            pq.push(*first);
        }
        else if (comp(*first, pq.top())) {
            pq.pop();
            pq.push(*first);
        }
    }
    return pq.top();
}

#endif
