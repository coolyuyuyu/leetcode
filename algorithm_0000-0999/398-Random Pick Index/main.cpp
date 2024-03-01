class Solution {
public:
    Solution(vector<int>& nums)
        : m_nums(nums) {
    }

    int pick(int target) {
        // reservoir sampling

        int ret;
        for (int i = 0, k = 0; i < m_nums.size(); ++i) {
            if (m_nums[i] != target) { continue; }
            if (std::rand() % ++k == 0) {
                ret = i;
            }
        }

        return ret;
    }

private:
    const vector<int>& m_nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
