class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        int n = nums.size();
        nums.insert(nums.begin(), 0);

        // dp[i]: the minimum sum of nums[1:i]
        long long dp[n + 1];
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = LLONG_MAX / 2;
        }

        long long minDpByRem[k];
        minDpByRem[0] = 0;
        for (int i = 1; i < k; ++i) {
            minDpByRem[i] = LLONG_MAX / 2;
        }

        long long presum = 0;
        for (int i = 1; i <= n; ++i) {
            presum += nums[i];

            dp[i] = std::min(dp[i], dp[i - 1] + nums[i]);

            int r = presum % k;
            dp[i] = std::min(dp[i], minDpByRem[r]);

            minDpByRem[r] = std::min(minDpByRem[r], dp[i]);
        }

        return dp[n];
    }
};
