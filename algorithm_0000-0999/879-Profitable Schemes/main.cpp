class Solution {
public:
    int M = 1e9 + 7;

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m = group.size();
        group.insert(group.begin(), 0);
        profit.insert(profit.begin(), 0);

        // dp[i][j][k]: the number of schemes such that from the first i crimes with j members participation and generate k profit
        int dp[m + 1][n + 1][minProfit + 1];
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                for (int k = 0; k <= minProfit; ++k) {
                    dp[i][j][k] = 0;
                }
            }
        }
        dp[0][0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j <= n; ++j) {
                for (int k = 0; k <= minProfit; ++k) {
                    dp[i + 1][j][k] += dp[i][j][k];
                    dp[i + 1][j][k] %= M;
                    if (j + group[i + 1] <= n) {
                        dp[i + 1][j + group[i + 1]][std::min(minProfit, k + profit[i + 1])] += dp[i][j][k];
                        dp[i + 1][j + group[i + 1]][std::min(minProfit, k + profit[i + 1])] %= M;
                    }
                }
            }
        }

        int ret = 0;
        for (int j = 0; j <= n; ++j) {
            ret += dp[m][j][minProfit];
            ret %= M;
        }

        return ret;
    }
};
