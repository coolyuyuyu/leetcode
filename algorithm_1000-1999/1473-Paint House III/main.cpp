class Solution {
public:
    // Time: O(m^2 * n^2)
    int dp1(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        houses.insert(houses.begin(), 0);
        cost.insert(cost.begin(), vector<int>(n, 0));

        // dp[i][j][k]: the minimum cost of painting houses[1:i] to form j neighborhoods and the houses[i] is painted with color k
        int dp[m + 1][target + 1][n + 1];
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= target; ++j) {
                for (int k = 0; k <= n; ++k) {
                    dp[i][j][k] = INT_MAX / 2;
                }
            }
        }
        for (int k = 0; k <= n; ++k) {
            dp[0][0][k] = 0;
        }
        for (int i = 1; i <= m; ++i) {
            if (houses[i] != 0) {
                int curColor = houses[i];
                for (int j = 1; j <= target; ++j) {
                    for (int preColor = 0; preColor <= n; ++preColor) {
                        if (preColor != curColor) {
                            dp[i][j][curColor] = std::min(dp[i][j][curColor], dp[i - 1][j - 1][preColor]);
                        }
                        else {
                            dp[i][j][curColor] = std::min(dp[i][j][curColor], dp[i - 1][j][curColor]);
                        }
                    }
                }
            }
            else {
                for (int j = 1; j <= target; ++j) {
                    for (int curColor = 1; curColor <= n; ++curColor) {
                        for (int preColor = 0; preColor <= n; ++preColor) {
                            if (preColor != curColor) {
                                dp[i][j][curColor] = std::min(dp[i][j][curColor], dp[i - 1][j - 1][preColor] + cost[i][curColor - 1]);
                            }
                            else {
                                dp[i][j][curColor] = std::min(dp[i][j][curColor], dp[i - 1][j][preColor] + cost[i][curColor - 1]);
                            }
                        }
                    }
                }
            }
        }

        int ret = INT_MAX / 2;
        for (int k = 1; k <= n; ++k) {
            ret = std::min(ret, dp[m][target][k]);
        }

        return ret == INT_MAX / 2 ? -1 : ret;
    }

    // Time: O(m^2 * n)
    int dp2(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        houses.insert(houses.begin(), 0);
        cost.insert(cost.begin(), vector<int>(n, 0));

        // dp[i][j][k]: the minimum cost of painting houses[1:i] to form j neighborhoods and the houses[i] is painted with color k
        int dp[m + 1][target + 1][n + 1];
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= target; ++j) {
                for (int k = 0; k <= n; ++k) {
                    dp[i][j][k] = INT_MAX / 2;
                }
            }
        }
        for (int k = 0; k <= n; ++k) {
            dp[0][0][k] = 0;
        }
        for (int i = 1; i <= m; ++i) {
            if (houses[i] != 0) {
                int curColor = houses[i];
                for (int j = 1; j <= target; ++j) {
                    for (int preColor = 0; preColor <= n; ++preColor) {
                        if (preColor != curColor) {
                            dp[i][j][curColor] = std::min(dp[i][j][curColor], dp[i - 1][j - 1][preColor]);
                        }
                        else {
                            dp[i][j][curColor] = std::min(dp[i][j][curColor], dp[i - 1][j][curColor]);
                        }
                    }
                }
            }
            else {
                for (int j = 1; j <= target; ++j) {
                    vector<pair<int, int>> tmp; // <cost, color>
                    for (int preColor = 0; preColor <= n; ++preColor) {
                        tmp.emplace_back(dp[i - 1][j - 1][preColor], preColor);
                    }
                    std::partial_sort(tmp.begin(), tmp.begin() + 2, tmp.end());

                    for (int curColor = 1; curColor <= n; ++curColor) {
                        if (curColor != tmp[0].second) {
                            dp[i][j][curColor] = std::min(dp[i][j][curColor], tmp[0].first + cost[i][curColor - 1]);
                        }
                        else {
                            dp[i][j][curColor] = std::min(dp[i][j][curColor], tmp[1].first + cost[i][curColor - 1]);
                        }
                        dp[i][j][curColor] = std::min(dp[i][j][curColor], dp[i - 1][j][curColor] + cost[i][curColor - 1]);
                    }
                }
            }
        }

        int ret = INT_MAX / 2;
        for (int k = 1; k <= n; ++k) {
            ret = std::min(ret, dp[m][target][k]);
        }

        return ret == INT_MAX / 2 ? -1 : ret;
    }

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        //return dp1(houses, cost, m, n, target);
        return dp2(houses, cost, m, n, target);
    }
};
