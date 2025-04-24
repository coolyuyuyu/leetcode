class MovingAverage {
public:
    MovingAverage(int size)
        : m_capacity(size)
        , m_sum(0) {
    }

    double next(int val) {
        if (m_vals.size() >= m_capacity) {
            m_sum -= m_vals.front();
            m_vals.pop();
        }
        m_vals.push(val);
        m_sum += val;

        return 1.0 * m_sum / m_vals.size();
    }

private:
    int m_capacity;
    queue<int> m_vals;
    int m_sum;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
