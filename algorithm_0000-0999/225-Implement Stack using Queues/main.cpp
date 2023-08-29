class StackImpl {
public:
    virtual void push(int x) = 0;
    virtual int pop() = 0;
    virtual int top() = 0;
    virtual bool empty()= 0;
};

class StackImpl1 : public StackImpl {
public:
    // Time: O(n)
    void push(int x) {
        m_q.push(x);
        for (int n = m_q.size() - 1; 0 < n--;) {
            m_q.push(m_q.front());
            m_q.pop();
        }
    }

    // Time: O(1)
    int pop() {
        int ret = top();
        m_q.pop();

        return ret;
    }

    // Time: O(1)
    int top() {
        return m_q.front();
    }

    // Time: O(1)
    bool empty() {
        return m_q.empty();
    }

private:
    queue<int> m_q;
};

class MyStack {
public:
    MyStack() {
        pImpl = new StackImpl1();
    }

    void push(int x) {
        pImpl->push(x);
    }

    int pop() {
        return pImpl->pop();
    }

    int top() {
        return pImpl->top();
    }

    bool empty() {
        return pImpl->empty();
    }

private:
    StackImpl* pImpl;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
 