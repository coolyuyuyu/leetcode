class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
    }

    /** Push element x onto stack. */
    void push(int x) {
        m_q.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        size_t count = m_q.size();
        for (size_t i = 0; i < (count - 1); ++i) {
            int d = m_q.front();
            m_q.pop();
            m_q.push(d);
        }
        int d = m_q.front();
        m_q.pop();
        return d;
    }

    /** Get the top element. */
    int top() {
        return m_q.back();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return m_q.empty();
    }

private:
    queue<int> m_q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */