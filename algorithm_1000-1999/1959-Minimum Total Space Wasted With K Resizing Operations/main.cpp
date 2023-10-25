class Solution {
public:
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        int n = nums.size();

        // dp[i][j]: the minimum total space wasted if nums[0:i] was resized j times
        int dp[n][k + 1];
        for (int i = 0, rangeMax = INT_MIN, rangeSum = 0; i < n; ++i) {
            rangeMax = std::max(rangeMax, nums[i]);
            rangeSum += nums[i];
            dp[i][0] = rangeMax * (i + 1) - rangeSum;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= std::min(i, k); ++j) {
                dp[i][j] = INT_MAX;

                int rangeMax = INT_MIN, rangeSum = 0;
                for (int s = i; s >= j; --s) {
                    rangeMax = std::max(rangeMax, nums[s]);
                    rangeSum += nums[s];
                    dp[i][j] = std::min(dp[i][j], dp[s - 1][j - 1] + rangeMax * (i - s + 1) - rangeSum);
                }
            }
        }

        int ret = INT_MAX;
        for (int j = 0; j <= k; ++j) {
            ret = std::min(ret, dp[n - 1][j]);
        }

        return ret;
    }
};
