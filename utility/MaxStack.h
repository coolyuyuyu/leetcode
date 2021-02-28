/*
TODO:
    1. Generalize compare object as a template parameter of MaxStack
    2. throw exception when invalid operation (pop from empty, max from empty)
    3. Restrict T only for numeric type
    4. template parameter std::less
*/

#include <cassert>
#include <vector>

template <typename T>
class MaxStack {
public:
    MaxStack() {
    }

    void clear() {
        m_data.clear();
        m_maxIndexes.clear();
    }

    void push(const T& val) {
        m_data.push_back(val);

        if (m_maxIndexes.empty() || m_data[m_maxIndexes.back()] <= m_data.back()) {
            m_maxIndexes.push_back(m_data.size() - 1);
        }
    }

    template <class... Args>
    void emplace(Args&&... args) {
        m_data.emplace_back(args...);

        if (m_maxIndexes.empty() || m_data[m_maxIndexes.back()] <= m_data.back()) {
            m_maxIndexes.push_back(m_data.size() - 1);
        }
    }

    void pop() {
        assert(!empty());

        if (m_data.size() == (m_maxIndexes.back() + 1)) {
            m_maxIndexes.pop_back();
        }

        m_data.pop_back();
    }

    const T& top() {
        assert(!empty());

        return m_data.back();
    }

    const T& top() const {
        return const_cast<MaxStack<T>*>(this)->top();
    }

    const T& max() {
        assert(!empty());

        return m_data[m_maxIndexes.back()];
    }

    const T& max() const {
        return const_cast<MaxStack<T>*>(this)->max();
    }

    bool empty() const {
        return m_data.empty();
    }

    size_t size() const {
        return m_data.size();
    }

private:
    std::vector<T> m_data;
    std::vector<size_t> m_maxIndexes;
};