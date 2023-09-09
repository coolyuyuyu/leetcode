class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // dp[i]: the number of possible combinations that add up to target
        vector<unsigned long long> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int num : nums) {
                if (num <= i) {
                    dp[i] += dp[i - num];
                }
            }
        }

        return dp[target];
    }
};
