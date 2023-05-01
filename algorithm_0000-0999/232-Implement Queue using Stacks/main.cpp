class MyQueue {
public:
    MyQueue() {
    }

    // Time: O(1)
    void push(int x) {
        m_stkI.push(x);
    }

    // Time: Amortized O(1)
    int pop() {
        int ret = peek();
        m_stkO.pop();
        return ret;
    }

    // Time: Amortized O(1)
    int peek() {
        if (m_stkO.empty()) {
            while (!m_stkI.empty()) {
                m_stkO.push(m_stkI.top());
                m_stkI.pop();
            }
        }

        return m_stkO.top();
    }

    // Time: O(1)
    bool empty() {
        return m_stkI.empty() && m_stkO.empty();
    }

private:
    stack<int> m_stkI;
    stack<int> m_stkO;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
