class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        m_stk1.push(homepage);
    }

    void visit(string url) {
        m_stk1.push(url);
        while (!m_stk2.empty()) {
           m_stk2.pop();
        }
    }

    string back(int steps) {
        for (; 0 < steps && 1 < m_stk1.size(); steps--) {
            m_stk2.push(m_stk1.top());
            m_stk1.pop();
        }

        return m_stk1.top();
    }

    string forward(int steps) {
        for (; 0 < steps && 0 < m_stk2.size(); steps--) {
            m_stk1.push(m_stk2.top());
            m_stk2.pop();
        }

        return m_stk1.top();
    }

private:
    stack<string> m_stk1;
    stack<string> m_stk2;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
