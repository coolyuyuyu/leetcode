class Solution {
public:
    int byDp(vector<int>& nums, int k) {
        int n = nums.size();

        nums.insert(nums.begin(), 0);

        vector<int> presum(n + 1);
        std::partial_sum(nums.begin(), nums.end(), presum.begin());
        std::function<int(int, int)> sum = [&](int lo, int hi) {
            return presum[hi] - presum[lo - 1];
        };

        // dp[i][numParts]: the minimized largest sum of the numParts split of nums[1:i]
        vector<vector<int>> dp(n + 1, vector<int>(k + 1));
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = INT_MAX;
        }
        for (int i = 1; i <= n; ++i) {
            for (int numParts = 1; numParts <= std::min(i, k); ++numParts) {
                dp[i][numParts] = INT_MAX;
                for (int j = i; numParts <= j; --j) {
                    dp[i][numParts] = std::min(dp[i][numParts], std::max(dp[j - 1][numParts - 1], sum(j, i)));
                }
            }
        }

        return dp[n][k];
    }

    int splitArray(vector<int>& nums, int k) {
        return byDp(nums, k);    
    }
};