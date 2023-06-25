class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();

        nums.insert(nums.begin(), 0);

        vector<int> presum(n + 1);
        std::partial_sum(nums.begin(), nums.end(), presum.begin());
        std::function<double(int lft, int rht)> avg = [&](int lft, int rht) {
            int sum = presum[rht] - presum[lft - 1];
            return static_cast<double>(sum) / (rht - lft + 1);
        };

        // dp[i][numParts]: the maximum score of nums[1:i] such that nums[1:i] is partitioned into numParts subarrays
        vector<vector<double>> dp(n + 1, vector<double>(k + 1));
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = -DBL_MAX;
        }
        for (int i = 1; i <= n; ++i) {
            for (int numParts = 1; numParts <= std::min(i, k); ++numParts) {
                for (int j = i; numParts <= j; j--) {
                    dp[i][numParts] = std::max(dp[i][numParts], dp[j - 1][numParts - 1] + avg(j, i));
                }
            }
        }

        double ret = 0.0;
        for (int numParts = 1; numParts <= k; ++numParts) {
            ret = std::max(ret, dp[n][numParts]);
        }

        return ret;
    }
};
