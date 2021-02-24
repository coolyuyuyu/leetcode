class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }

    /** Push element x to the back of queue. */
    // Time: O(1)
    void push(int x) {
        m_stkI.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    // Time: Amortized O(1)
    int pop() {
        if (m_stkO.empty()) {
            while (!m_stkI.empty()) {
                m_stkO.push(m_stkI.top());
                m_stkI.pop();
            }
        }
        int val = m_stkO.top();
        m_stkO.pop();
        return val;
    }

    /** Get the front element. */
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

    /** Returns whether the queue is empty. */
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