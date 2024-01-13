class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // dp[t]: the number of possible combinations that add up to t
        unsigned dp[target + 1];
        std::fill(dp, dp + target + 1, 0);
        dp[0] = 1;

        for (int i = 0; i <= target; ++i) {
            for (int num : nums) {
                if (num <= i) {
                    dp[i] += dp[i - num];
                }
            }
        }

        return dp[target];
    }
};
