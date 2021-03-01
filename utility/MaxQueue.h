/*
TODO:
    1. support custom allocator
    2. support range-based constructor
    3. support initializer-list constructor
    4. Restrict T only for numeric type
*/

#include <algorithm>
#include <functional>

#include "MaxStack.h"

template <class T, class Compare = std::less<T>>
class MaxQueue {
public:
    MaxQueue() {
    }

    explicit MaxQueue(const Compare& comp)
        : m_stkI(comp)
        , m_stkO(comp) {
    }

    void clear() {
        m_stkI.clear();
        m_stkO.clear();
    }

    void swap(MaxQueue<T>& rhs) {
        m_stkI.swap(rhs.m_stkI);
        m_stkO.swap(rhs.m_stkO);
    }

    void push(const T& v) {
        m_stkI.push(v);
    }

    template <class... Args>
    void emplace(Args&&... args) {
        m_stkI.emplace(args...);
    }

    void pop() {
        assert(!empty());
        if (m_stkO.empty()) {
            while (!m_stkI.empty()) {
                m_stkO.push(m_stkI.top());
                m_stkI.pop();
            }
        }

        m_stkO.pop();
    }

    const T& front() {
        assert(!empty());
        if (m_stkO.empty()) {
            while (!m_stkI.empty()) {
                m_stkO.push(m_stkI.top());
                m_stkI.pop();
            }
        }

        return m_stkO.top();
    }

    const T& front() const {
        return const_cast<MaxQueue<T, Compare>*>(this)->front();
    }

    const T& max() {
        assert(!empty());
        if (m_stkI.empty()) {
            assert(!m_stkO.empty());
            return m_stkO.max();
        }
        else {
            if (m_stkO.empty()) {
                return m_stkI.max();
            }
            else {
                return std::max(m_stkI.max(), m_stkO.max());
            }
        }
    }

    const T& max() const {
        return const_cast<MaxQueue<T, Compare>*>(this)->max();
    }

    bool empty() const {
        return (m_stkI.empty() && m_stkO.empty());
    }

    size_t size() const {
        return (m_stkI.size() + m_stkO.size());
    }

private:
    MaxStack<T, Compare> m_stkI;
    MaxStack<T, Compare> m_stkO;
};
