class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();

        // dp[i][0]: the maximum sum from nums[0:i] with NO sign change at nums[i]
        // dp[i][0]: the maximum sum from nums[0:i] with sign change at nums[i]
        long long dp[n][2];
        dp[0][0] = nums[0], dp[0][1] = LLONG_MIN;

        for (int i = 1; i < n; ++i) {
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1]) + nums[i];
            dp[i][1] = dp[i - 1][0] - nums[i];
        }

        return std::max(dp[n - 1][0], dp[n - 1][1]);
    }
};
