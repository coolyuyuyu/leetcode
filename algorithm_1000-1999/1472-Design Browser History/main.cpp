class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        m_stkBwd.push(homepage);
    }

    void visit(string url) {
        m_stkBwd.push(url);
        while (!m_stkFwd.empty()) {
            m_stkFwd.pop();
        }
    }

    string back(int steps) {
        for (; steps && 1 < m_stkBwd.size(); --steps) {
            m_stkFwd.push(m_stkBwd.top());
            m_stkBwd.pop();
        }

        return m_stkBwd.top();
    }

    string forward(int steps) {
        for (; steps && !m_stkFwd.empty(); --steps) {
            m_stkBwd.push(m_stkFwd.top());
            m_stkFwd.pop();
        }

        return m_stkBwd.top();
    }

private:
    stack<string> m_stkBwd;
    stack<string> m_stkFwd;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
