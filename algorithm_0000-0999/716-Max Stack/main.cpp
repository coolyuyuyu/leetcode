class MaxStack {
public:
    MaxStack() {
    }

    void push(int x) {
        m_elems.push_back(x);

        if (m_maxElems.empty()) {
            m_maxElems.push_back(x);
        }
        else {
            m_maxElems.push_back(max(m_maxElems.back(), x));
        }
    }

    int pop() {
        int ans = m_elems.back();

        m_elems.pop_back();
        m_maxElems.pop_back();

        return ans;
    }

    int top() {
        return m_elems.back();
    }

    int peekMax() {
        return m_maxElems.back();
    }

    int popMax() {
        int ans = peekMax();

        size_t index = m_elems.size() - (find(m_elems.rbegin(), m_elems.rend(), ans) - m_elems.rbegin());
        vector<int> buffer(m_elems.begin() + index, m_elems.end());
        m_elems.resize(index - 1);
        m_maxElems.resize(index - 1);

        for (int val : buffer) {
            push(val);
        }

        return ans;
    }

private:
    vector<int> m_elems;
    vector<int> m_maxElems;
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */