class CustomStack {
public:
    CustomStack(int maxSize)
        : m_size(0)
        , m_capacity(maxSize)
        , m_data(new int[m_capacity]) {
    }

    ~CustomStack() {
        delete[] m_data;
    }

    void push(int x) {
        if (!full()) {
            m_data[m_size++] = x;
        }
    }

    int pop() {
        return (empty() ? -1 : m_data[--m_size]);
    }

    bool empty() const {
        return (m_size == 0);
    }

    bool full() {
        return (m_size == m_capacity);
    }

    void increment(int k, int val) {
        if (m_size < k) {
            k = m_size;
        }

        for (int i = 0; i < k; ++i) {
            m_data[i] += val;
        }
    }

private:
    int m_size;
    int m_capacity;
    int* m_data;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */