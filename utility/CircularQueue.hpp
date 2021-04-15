template <typename T>
class CircularQueue {
public:
    CircularQueue(size_t capacity)
        : m_size(0)
        , m_capacity(capacity)
        , m_index(0)
        , m_data(new T[m_capacity]) {
    }

    ~CircularQueue() {
        delete[] m_data;
    }

    bool push(T value) {
        if (full()) {
            return false;
        }
        else {
            m_data[(m_index + m_size) % m_capacity] = value;
            ++m_size;
            return true;
        }
    }

    bool pop() {
        if (empty()) {
            return false;
        }
        else {
            m_index = (m_index + 1) % m_capacity;
            --m_size;
            return true;
        }
    }

    T& front() {
        return (empty() ? -1 : m_data[m_index]);
    }

    const &T front() const {
        return const_cast<CircularQueue*>(this)->front();
    }

    T& back() {
        return (empty() ? -1 : m_data[(m_index + m_size - 1) % m_capacity]);
    }

    const &T back() const {
        return const_cast<CircularQueue*>(this)->back();
    }

    bool empty() const {
        return (m_size == 0);
    }

    bool full() const {
        return (m_size == m_capacity);
    }

    size_t size() const {
        return m_size;
    }

private:
    size_t m_size;
    size_t m_capacity;
    size_t m_index;
    T* m_data;
};
