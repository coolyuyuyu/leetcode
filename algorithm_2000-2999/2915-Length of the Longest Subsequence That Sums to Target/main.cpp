class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();

        nums.insert(nums.begin(), 0);

        // dp[i][t]: the length of the longest subsequence of nums[:i] that sums up to target
        int dp[n + 1][target + 1];
        dp[0][0] = 0;
        for (int t = 1; t <= target; ++t) {
            dp[0][t] = -1;
        }
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            for (int t = 1; t <= target; ++t) {
                dp[i][t] = dp[i - 1][t];
                if (nums[i] <= t && dp[i - 1][t - nums[i]] != -1) {
                    dp[i][t] = std::max(dp[i][t], dp[i - 1][t - nums[i]] + 1);
                }
            }
        }

        return dp[n][target];
    }
};
