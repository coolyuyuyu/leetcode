class Solution {
public:
    int M = 1e9 + 7;
    int dp[101][101][101];

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        dp[0][0][0] = 1;

        int m = group.size();
        group.insert(group.begin(), 0);
        profit.insert(profit.begin(), 0);

        for (int i = 0; i < m; ++i) { // crime
            for (int j = 0; j <= n; ++j) { // member
                for (int k = 0; k <= minProfit; ++k) { // profit
                    dp[i + 1][j][k] += dp[i][j][k];
                    dp[i + 1][j][k] %= M;

                    if ((j + group[i + 1]) <= n) {
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
