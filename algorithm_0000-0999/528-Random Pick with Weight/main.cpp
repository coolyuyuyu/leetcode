class Solution {
public:
    Solution(vector<int>& w)
        : m_presum(w.size()) {
        std::partial_sum(w.begin(), w.end(), m_presum.begin());
    }

    int pickIndex() {
        int i = rand() % m_presum.back();
        return std::distance(m_presum.begin(), std::upper_bound(m_presum.begin(), m_presum.end(), i));
    }

private:
    vector<int> m_presum;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
