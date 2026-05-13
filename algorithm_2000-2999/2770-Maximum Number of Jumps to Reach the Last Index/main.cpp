class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();

        // dp[i]: the maximum number of jumps to reach i
        int dp[n];
        std::fill(dp, dp + n, INT_MIN);

        dp[0] = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] > INT_MIN && std::abs(nums[j] - nums[i]) <= target) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n - 1] > INT_MIN ? dp[n - 1] : -1;
    }
};
