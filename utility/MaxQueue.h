#include <algorithm>
#include <stdexcept>

#include "MaxStack.h"

template <typename T>
class MaxQueue {
public:
    MaxQueue () {
    }

    void clear() {
        m_stkI.clear();
        m_stkO.clear();
    }

    void push(const T& v) {
        m_stkI.push(v);
    }

    template <class... Args>
    void emplace (Args&&... args) {
        m_stkI.emplace(args...);
    }

    void pop() {
        if (m_stkO.empty()) {
            while (!m_stkI.empty()) {
                m_stkO.push(m_stkI.top());
                m_stkI.pop();
            }
        }

        m_stkO.pop();
    }

    const T& front() {
        if (m_stkO.empty()) {
            while (!m_stkI.empty()) {
                m_stkO.push(m_stkI.top());
                m_stkI.pop();
            }
        }

        return m_stkO.top();
    }

    const T& front() const {
        return const_cast<MaxStack<T>*>(this)->front();
    }

    const T& max() {
        if (m_stkI.empty() && m_stkO.empty()) {
            throw std::domain_error(std::string("empty"));
        }
        else if (!m_stkI.empty() && m_stkO.empty()) {
            return m_stkI.max();
        }
        else if (m_stkI.empty() && !m_stkO.empty()) {
            return m_stkO.max();
        }
        else {
            return std::max(m_stkI.max(), m_stkO.max());
        }
    }

    const T& max() const {
        return const_cast<MaxStack<T>*>(this)->max();
    }

    bool empty() const {
        return (m_stkI.empty() && m_stkO.empty());
    }

    size_t size() const {
        return (m_stkI.size() + m_stkO.size());
    }

private:
    MaxStack<T> m_stkI;
    MaxStack<T> m_stkO;
};