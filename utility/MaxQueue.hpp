#ifndef __MAX_QUEUE_HPP__6B83AD37_F458_4458_A560_74A86402E184
#define __MAX_QUEUE_HPP__6B83AD37_F458_4458_A560_74A86402E184

/*
TODO:
    1. support custom allocator
    2. support range-based constructor
    3. support initializer-list constructor
    4. Restrict T only for numeric type
*/

#include <algorithm>
#include <cassert>
#include <functional>
#include <type_traits>
#include <utility>
#include <vector>

#include "MaxStack.hpp"

template <class T, class Container = std::vector<T>, class Compare = std::less<typename Container::value_type>>
class MaxQueue {
public:
    explicit MaxQueue(const Compare& comp = Compare())
        : m_stkI(comp)
        , m_stkO(comp) {
    }

    void clear() {
        m_stkI.clear();
        m_stkO.clear();
    }

    void swap(MaxQueue<T>& rhs) {
        std::swap(m_stkI, rhs.m_stkI);
        std::swap(m_stkO, rhs.m_stkO);
    }

    void push(const T& v) {
        m_stkI.push(v);
    }

    template <class... Args>
    void emplace(Args&&... args) {
        m_stkI.emplace(std::forward<Args>(args)...);
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
        return static_cast<typename std::remove_reference<decltype(*this)>::type const&>(*this).front();
    }

    const T& front() const {
        assert(!empty());
        if (m_stkO.empty()) {
            while (!m_stkI.empty()) {
                m_stkO.push(m_stkI.top());
                m_stkI.pop();
            }
        }

        return m_stkO.top();
    }

    const T& max() {
        return static_cast<typename std::remove_reference<decltype(*this)>::type const&>(*this).max();
    }

    const T& max() const {
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

    bool empty() const {
        return (m_stkI.empty() && m_stkO.empty());
    }

    size_t size() const {
        return (m_stkI.size() + m_stkO.size());
    }

private:
    MaxStack<T, Container, Compare> m_stkI;
    MaxStack<T, Container, Compare> m_stkO;
};

#endif
