class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
    }

    /** Push element x onto stack. */
    // Time: O(n)
    void push(int x) {
        m_q2.push(x);
        while (!m_q1.empty()) {
            m_q2.push(m_q1.front());
            m_q1.pop();
        }
        m_q1.swap(m_q2);
    }

    /** Removes the element on top of the stack and returns that element. */
    // Time: O(1)
    int pop() {
        int val = top();
        m_q1.pop();
        return val;
    }

    /** Get the top element. */
    // Time: O(1)
    int top() {
        return m_q1.front();
    }

    /** Returns whether the stack is empty. */
    // Time: O(1)
    bool empty() {
        return m_q1.empty();
    }

private:
    queue<int> m_q1;
    queue<int> m_q2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */