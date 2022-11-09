class StockSpanner {
public:
    StockSpanner() {
    }

    int next(int price) {
        int count = 1;
        while (!m_stk.empty() && m_stk.top().first <= price) {
            count += m_stk.top().second;
            m_stk.pop();
        }
        m_stk.emplace(price, count);

        return count;
    }

private:
    stack<pair<int, int>> m_stk; // <price, count>
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
 