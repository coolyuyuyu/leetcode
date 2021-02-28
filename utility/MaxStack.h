/*
TODO:
    1. Generalize compare object as a template parameter of MaxStack
    2. throw exception when invalid operation (pop from empty, max from empty)
    3. Restrict T only for numeric type
*/

#include <vector>

template <typename T>
class MaxStack {
public:
    MaxStack() {
    }

    void push(const T& val) {
        m_data.push_back(val);

        if (m_max.empty() || m_max.back() <= val) {
            m_max.push_back(val);
        }
    }

    template <class... Args>
    void emplace(Args&&... args) {
        m_data.emplace_back(args...);

        if (m_max.empty() || m_max.back() <= m_data.back()) {
            m_max.push_back(m_data.back());
        }
    }

    void pop() {
        if (m_data.back() == max()) {
            m_max.pop_back();
        }

        m_data.pop_back();
    }

    const T& top() {
        return m_data.back();
    }

    const T& top() const {
        return const_cast<MaxStack<T>*>(this)->top();
    }

    const T& max() {
        return m_max.back();
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
    std::vector<T> m_max;
};