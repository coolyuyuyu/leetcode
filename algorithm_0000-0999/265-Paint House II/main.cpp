class Solution {
public:
    // Time: O(nm^2)
    int dp1(vector<vector<int>>& costs) {
        int n = costs.size(), m = costs.empty() ? 0 : costs[0].size();

        costs.insert(costs.begin(), vector<int>());

        // dp[i][j] : the minimum cost to paint houses[1:i] and house[j] is painted with jth color
        int dp[n + 1][m];
        for (int j = 0; j < m; ++j) {
             dp[0][j] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < m; ++j) {
                dp[i][j] = INT_MAX;
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < m; ++k) {
                    if (k != j) {
                        dp[i][j] = std::min(dp[i][j], dp[i - 1][k] + costs[i][j]);
                    }
                }
            }
        }

        int ret = INT_MAX;
        for (int j = 0; j < m; ++j) {
            ret = std::min(ret, dp[n][j]);
        }

        return ret;
    }

    // Time: O(nm)
    int dp2(vector<vector<int>>& costs) {
        int n = costs.size(), m = costs.empty() ? 0 : costs[0].size();

        costs.insert(costs.begin(), vector<int>());

        // dp[i][j] : the minimum cost to paint houses[1:i] and house[j] is painted with jth color
        int dp[n + 1][m];
        for (int j = 0; j < m; ++j) {
             dp[0][j] = 0;
        }

        int curColor1 = 0, curColor2 = 1;
        for (int i = 1; i <= n; ++i) {
            int preColor1 = curColor1, preColor2 = curColor2;
            int minCost1 = INT_MAX, minCost2 = INT_MAX;
            for (int j = 0; j < m; ++j) {
                dp[i][j] = dp[i - 1][j == preColor1 ? preColor2 : preColor1] + costs[i][j];
                if (dp[i][j] < minCost1) {
                    curColor2 = curColor1;
                    minCost2 = minCost1;
                    curColor1 = j;
                    minCost1 = dp[i][j];
                }
                else if (dp[i][j] < minCost2) {
                    curColor2 = j;
                    minCost2 = dp[i][j];
                }
            }
        }

        return dp[n][curColor1];
    }

    int minCostII(vector<vector<int>>& costs) {
        //return dp1(costs);
        return dp2(costs);
    }
};
