class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (target < -sum || target > sum) {
            return 0;
        }

        nums.insert(nums.begin(), 0);

        int offset = sum;

        // dp[i][s]: the number of different expressions that you can build from nums[1:i], which evaluates to s
        int dp[n + 1][sum * 2 + 1];
        for (int s = -sum; s <= sum; ++s) {
            dp[0][s + offset] = 0;
        }
        dp[0][0 + offset] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int s = -sum; s <= sum; ++s) {
                dp[i][s + offset] = 0;
                if (s - nums[i] >= -sum) {
                    dp[i][s + offset] += dp[i - 1][s - nums[i] + offset];
                }
                if (s + nums[i] <= sum) {
                    dp[i][s + offset] += dp[i - 1][s + nums[i] + offset];
                }
            }
        }

        return dp[n][target + offset];
    }
};
