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
#include <vector>

template <class T, class Container = std::vector<T>, class Compare = std::less<typename Container::value_type>>
class MaxStack {
public:
    explicit MaxStack(const Compare& comp = Compare())
        : m_comp(comp) {
    }

    void clear() {
        m_elems.clear();
        m_indexes.clear();
    }

    void swap(MaxStack<T>& rhs) {
        std::swap(m_elems, rhs.m_elems);
        std::swap(m_indexes, rhs.m_indexes);
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

        Container buf(m_elems.size() - maxIndex - 1);
        std::move(m_elems.begin() + maxIndex + 1, m_elems.end(), buf.begin());

        m_elems.erase(m_elems.begin() + maxIndex, m_elems.end());

        for (const T& elem: buf) {
            push(elem);
        }
    }

    const T& top() {
        return static_cast<typename std::remove_reference<decltype(*this)>::type const&>(*this).top();
    }

    const T& top() const {
        assert(!empty());
        return m_elems.back();
    }

    const T& max() {
        return static_cast<typename std::remove_reference<decltype(*this)>::type const&>(*this).max();
    }

    const T& max() const {
        assert(!empty());
        return m_elems[m_indexes.back()];
    }

    bool empty() const {
        assert(m_elems.empty() == m_indexes.empty());
        return m_elems.empty();
    }

    size_t size() const {
        return m_elems.size();
    }

private:
    Container m_elems;
    std::vector<size_t> m_indexes;
    Compare m_comp;
};
