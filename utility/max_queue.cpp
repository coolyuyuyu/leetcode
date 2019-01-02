class MonoQueue {
public:
    MonoQueue() {
    }

    void push(int val) {
        size_t count = 0;
        while (!m_deque.empty() && m_deque.back().first < val) {
            count += m_deque.back().second + 1;
            m_deque.pop_back();
        }

        m_deque.emplace_back(val, count);
    }

    void pop() {
        if (0 < m_deque.front().second) {
            --(m_deque.front().second);
            return;
        }

        m_deque.pop_front();
    }

    int max() {
        return m_deque.front().first;
    }

private:
    deque<pair<int, size_t>> m_deque;
};