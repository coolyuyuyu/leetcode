class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty()) {
            return 0;
        }

        size_t n = costs.size();
        size_t k = costs.front().size();
        vector<vector<int>> dp(n, vector<int>(k));
        dp[0] = costs[0];
        for (size_t x = 1; x < n; ++x) {
            for (size_t y = 0; y < k; ++y) {
                int minDpOfOthers = INT_MAX;
                for (size_t z = 0; z < k; ++z) {
                    if (z == y) {
                        continue;
                    }
                    minDpOfOthers = min(minDpOfOthers, dp[x - 1][z]);
                }

                dp[x][y] = minDpOfOthers + costs[x][y];
            }
        }

        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};