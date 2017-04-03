class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        m_in.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (m_out.empty()) {
            peek();
        }
        int d = m_out.top();
        m_out.pop();
        return d;
    }

    /** Get the front element. */
    int peek() {
        if (m_out.empty()) {
            while (!m_in.empty()) {
                m_out.push(m_in.top());
                m_in.pop();
            }
        }
        return m_out.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return m_in.empty() && m_out.empty();
    }

private:
    stack<int> m_in;
    stack<int> m_out;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */