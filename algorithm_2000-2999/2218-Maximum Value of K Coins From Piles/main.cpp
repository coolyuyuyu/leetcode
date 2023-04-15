class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();

        vector<vector<int>> presum(n);
        for (int i = 0; i < n; ++i) {
            presum[i].push_back(0);
            for (int j = 0, sum = 0; j < piles[i].size(); ++j) {
                sum += piles[i][j];
                presum[i].push_back(sum);
            }
        }

        //dp[i][j]: the maximum total value of j coins from piles[0:i]
        vector<vector<int>> dp(n, vector<int>(k + 1));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= k; ++j) {
                for (int t = 0; t <= std::min<int>(j, piles[i].size()); ++t) {
                    dp[i][j] = std::max(dp[i][j], (i == 0 ? 0 : dp[i - 1][j - t]) + presum[i][t]);
                }
            }
        }

        return dp[n - 1][k];
    }
};
