class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        std::sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.insert(cuts.end(), n);

        int m = cuts.size();

        vector<vector<int>> dp(m + 1, vector<int>(m + 1, INT_MAX)); // the total cost of of the cuts for the wood stick of cuts[i] -> cuts[j]
        for (int i = 0; (i + 1) < m; ++i) {
            dp[i][i + 1] = 0;
        }
        for (int len = 3; len <= m; ++len) {
            for (int i = 0; (i + len - 1) < m; ++i) {
                int j = i + len - 1;
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = std::min(dp[i][j], cuts[j] - cuts[i] + dp[i][k] + dp[k][j]);
                }
            }
        }

        return dp[0][m - 1];
    }
};
