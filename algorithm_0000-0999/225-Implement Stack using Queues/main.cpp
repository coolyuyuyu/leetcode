class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
    }

    /** Push element x onto stack. */
    // Time: O(1)
    void push(int x) {
        if (!m_qO.empty()) {
            m_qI.push(m_qO.front());
            m_qO.pop();
        }
        m_qO.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    // Time: O(n)
    int pop() {
        int val = top();
        m_qO.pop();

        while (1 < m_qI.size()) {
            m_qO.push(m_qI.front());
            m_qI.pop();
        }
        m_qO.swap(m_qI);

        return val;
    }

    /** Get the top element. */
    // Time: O(1)
    int top() {
        return m_qO.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return m_qO.empty();
    }

private:
    queue<int> m_qI;
    queue<int> m_qO;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */