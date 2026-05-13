class Solution {
public:
    Solution(vector<int>& nums)
        : m_original(nums)
        , m_nums(nums) {
    }

    vector<int> reset() {
        m_nums.assign(m_original.begin(), m_original.end());
        return m_nums;
    }

    vector<int> shuffle() {
        for (int i = m_nums.size(); 0 < i--;) {
            std::swap(m_nums[std::rand() % (i + 1)], m_nums[i]);
        }
        return m_nums;
    }

private:
    vector<int> m_original;
    vector<int> m_nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
