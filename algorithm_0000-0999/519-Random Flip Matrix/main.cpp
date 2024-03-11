class Solution {
public:
    Solution(int m, int n)
        : m_m(m)
        , m_n(n)
        , m_numBlacks(0) {
    }

    vector<int> flip() {
        int idx = rand() % (m_m * m_n - m_numBlacks);
        ++m_numBlacks;

        int ret = idx;
        if (m_black2white.find(ret) != m_black2white.end()) {
            ret = m_black2white[ret];
        }

        if (m_black2white.find(m_m * m_n - m_numBlacks) != m_black2white.end()) {
            m_black2white[idx] = m_black2white[m_m * m_n - m_numBlacks];
        }
        else {
            m_black2white[idx] = m_m * m_n - m_numBlacks;
        }

        return {ret / m_n, ret % m_n};
    }

    void reset() {
        m_numBlacks = 0;
        m_black2white.clear();
    }

private:
    int m_m;
    int m_n;
    int m_numBlacks;
    unordered_map<int, int> m_black2white;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
