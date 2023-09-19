class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();

        piles.insert(piles.begin(), vector<int>());

        int presum[n + 1][k + 1];
        for (int i = 1; i <= n; ++i) {
            presum[i][0] = 0;
            std::partial_sum(piles[i].begin(), piles[i].begin() + std::min<int>(k, piles[i].size()), presum[i] + 1);
        }

        // dp[i][j]: the maximum total value of j coins from piles[0:i]
        int dp[n + 1][k + 1];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                dp[i][j] = INT_MIN;
            }
        }
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                for (int t = 0; t <= std::min<int>(j, piles[i].size()); ++t) {
                    dp[i][j] = std::max(dp[i][j], dp[i - 1][j - t] + presum[i][t]);
                }
            }
        }
        return dp[n][k];
    }
};
