class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }

    void push(int x) {
        if (m_min.empty() || x <= m_min.back()) {
            m_min.push_back(x);
        }

        m_data.push_back(x);
    }

    void pop() {
        if (m_data.back() == getMin()) {
            m_min.pop_back();
        }

        m_data.pop_back();
    }

    int top() {
        return m_data.back();
    }

    int getMin() {
        return m_min.back();
    }

private:
    vector<int> m_data;
    vector<int> m_min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */