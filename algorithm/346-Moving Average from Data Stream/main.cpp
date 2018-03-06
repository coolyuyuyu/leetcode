class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size)
        : m_capacity(size) {
    }

    double next(int val) {
        if (m_vals.size() == m_capacity) {
            m_sum -= m_vals.front();
            m_vals.pop();
        }

        m_sum += val;
        m_vals.push(val);

        return m_sum * 1.0 / m_vals.size();
    }

private:
    size_t m_capacity;
    queue<int> m_vals;
    int m_sum = 0;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */