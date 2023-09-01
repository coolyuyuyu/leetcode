class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        nums.insert(nums.begin(), 0);

        int offset = 1000;

        // dp[i][s]: the number of different expressions that you can build from nums[1:i], which evaluates to s
        int dp[n + 1][2001];
        for (int s = -1000; s <= 1000; ++s) {
            dp[0][s + offset] = 0;
        }
        dp[0][0 + offset] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int s = -1000; s <= 1000; ++s) {
                dp[i][s + offset] = 0;
                if (-1000 <= (s - nums[i])) {
                    dp[i][s + offset] += dp[i - 1][s - nums[i] + offset];
                }
                if ((s + nums[i]) <= 1000) {
                    dp[i][s + offset] += dp[i - 1][s + nums[i] + offset];
                }
            }
        }

        return dp[n][target + offset];
    }
};
