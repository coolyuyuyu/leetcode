class Solution {
public:
    long long maximumStrength(vector<int>& nums, int k) {
        int n = nums.size();
        nums.insert(nums.begin(), 0);

        // dp[i][j][0]: select j subarrays from nums[1:i] and nums[i] is considered included in j-th subarray, the maximal value of sum[1]*k + sum[2]*(k-1) + ... + sum[j]*(k+1-j)
        // dp[i][j][0]: select j subarrays from nums[1:i] and nums[i] is considered excluded from j-th subarray, the maximal value of sum[1]*k + sum[2]*(k-1) + ... + sum[j]*(k+1-j)
        long long dp[n + 1][k + 1][2];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                dp[i][j][0] = LLONG_MIN / 2;
                dp[i][j][1] = LLONG_MIN / 2;
            }
        }
        for (int i = 0; i <= n; ++i) {
            dp[i][0][0] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                dp[i][j][0] = std::max({dp[i - 1][j][0], dp[i - 1][j][1]});
                dp[i][j][1] = std::max({dp[i - 1][j][1], dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]}) + (j & 1 ? 1LL : -1LL) * nums[i] * (k - j + 1);
            }
        }

        return std::max(dp[n][k][0], dp[n][k][1]);
    }
};
