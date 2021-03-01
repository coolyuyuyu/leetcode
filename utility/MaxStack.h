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
#include <vector>

template <class T, class Compare = std::less<T>>
class MaxStack {
public:
    MaxStack() {
    }

    explicit MaxStack(const Compare& comp)
        : m_comp(comp) {
    }

    void clear() {
        m_elems.clear();
        m_indexes.clear();
    }

    void swap(MaxStack<T>& rhs) {
        m_elems.swap(rhs.m_elems);
        m_indexes.swap(rhs.m_indexes);
    }

    void push(const T& val) {
        m_elems.push_back(val);
        if (m_indexes.empty()
            || m_comp(m_elems[m_indexes.back()], m_elems.back())
            || !m_comp(m_elems.back(), m_elems[m_indexes.back()])) {
            m_indexes.push_back(m_elems.size() - 1);
        }
    }

    template <class... Args>
    void emplace(Args&&... args) {
        m_elems.emplace_back(args...);
        if (m_indexes.empty()
            || m_comp(m_elems[m_indexes.back()], m_elems.back())
            || !m_comp(m_elems.back(), m_elems[m_indexes.back()])) {
            m_indexes.push_back(m_elems.size() - 1);
        }
    }

    void pop() {
        assert(!empty());
        if (m_elems.size() == (m_indexes.back() + 1)) {
            m_indexes.pop_back();
        }
        m_elems.pop_back();
    }

    void pop_max() {
        size_t maxIndex = m_indexes.back();
        m_indexes.pop_back();

        std::vector<T> buf(m_elems.size() - maxIndex - 1);
        std::move(m_elems.begin() + maxIndex + 1, m_elems.end(), buf.begin());

        m_elems.erase(m_elems.begin() + maxIndex, m_elems.end());

        for (const T& elem: buf) {
            push(elem);
        }
    }

    const T& top() {
        assert(!empty());
        return m_elems.back();
    }

    const T& top() const {
        return const_cast<MaxStack<T, Compare>*>(this)->top();
    }

    const T& max() {
        assert(!empty());
        return m_elems[m_indexes.back()];
    }

    const T& max() const {
        return const_cast<MaxStack<T, Compare>*>(this)->max();
    }

    bool empty() const {
        assert(m_elems.empty() == m_indexes.empty());
        return m_elems.empty();
    }

    size_t size() const {
        return m_elems.size();
    }

private:
    std::vector<T> m_elems;
    std::vector<size_t> m_indexes;
    Compare m_comp;
};
