class MovingAverage {
public:
    MovingAverage(int size)
        : m_capacity(size)
        , m_sum(0) {
    }

    double next(int val) {
        m_sum += val;
        m_dq.push_back(val);
        if (m_capacity < m_dq.size()) {
            m_sum -= m_dq.front();
            m_dq.pop_front();
        }

        return 1.0 * m_sum / m_dq.size();
    }

private:
    deque<int> m_dq;
    int m_capacity;
    int m_sum;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
