class CustomStack {
public:
    CustomStack(int maxSize)
        : m_capacity(maxSize)
        , m_size(0)
        , m_data(new int [m_capacity])
        , m_diff(new int [m_capacity]) {
    }

    void push(int x) {
        if (m_size == m_capacity) { return; }

        m_data[m_size] = x;
        m_diff[m_size] = 0;
        ++m_size;
    }

    int pop() {
        if (m_size == 0) { return -1; }

        int ret = m_data[m_size - 1] + m_diff[m_size - 1];
        --m_size;

        if (m_size > 0) {
            m_diff[m_size - 1] += m_diff[m_size];
        }

        return ret;
    }

    void increment(int k, int val) {
        if (m_size == 0) { return; }

        m_diff[std::min(k - 1, m_size - 1)] += val;
    }

private:
    int m_capacity;
    int m_size;
    int* m_data;
    int* m_diff;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
