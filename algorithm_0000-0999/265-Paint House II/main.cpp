class Solution {
public:
    // Time: O(nk^2)
    int dp1(vector<vector<int>>& costs) {
        int n = costs.size(), colors = costs.empty() ? 0 : costs[0].size();

        // dp[i][j]: the minimum cost to paint houses[0:i], and house i is painted jth color
        vector<vector<int>> dp(n + 1, vector<int>(colors));
        for (int color = 0; color < colors; ++color) {
            dp[0][color] = 0;
        }
        costs.insert(costs.begin(), vector<int>(colors));

        for (int i = 1; i <= n; ++i) {
            for (int color1 = 0; color1 < colors; ++color1) {
                int minVal = INT_MAX;
                for (int color2 = 0; color2 < colors; ++color2) {
                    if (color2 == color1) {
                        continue;
                    }
                    minVal = std::min(minVal, dp[i - 1][color2]);
                }

                dp[i][color1] = minVal + costs[i][color1];

            }
        }

        int ret = INT_MAX;
        for (int color = 0; color < colors; ++color) {
            ret = std::min(ret, dp[n][color]);
        }

        return ret;
    }

    // Time: O(nk)
    int dp2(vector<vector<int>>& costs) {
        int n = costs.size(), colors = costs.empty() ? 0 : costs[0].size();

        // dp[i][j]: the minimum cost to paint houses[0:i], and house i is painted jth color
        vector<vector<int>> dp(n + 1, vector<int>(colors));
        for (int color = 0; color < colors; ++color) {
            dp[0][color] = 0;
        }
        costs.insert(costs.begin(), vector<int>(colors));

        int colorOfMinCost1 = 0;
        int colorOfMinCost2 = 1;
        for (int i = 1; i <= n; ++i) {
            int preColorOfMinCost1 = colorOfMinCost1, preColorOfMinCost2 = colorOfMinCost2;
            int minCost1 = INT_MAX, minCost2 = INT_MAX;
            for (int color = 0; color < colors; ++color) {
                if (color != preColorOfMinCost1) {
                    dp[i][color] = dp[i - 1][preColorOfMinCost1] + costs[i][color];
                }
                else {
                    dp[i][color] = dp[i - 1][preColorOfMinCost2] + costs[i][color];
                }

                if (dp[i][color] < minCost1) {
                    minCost2 = minCost1;
                    colorOfMinCost2 = colorOfMinCost1;
                    minCost1 = dp[i][color];
                    colorOfMinCost1 = color;
                }
                else if (dp[i][color] < minCost2) {
                    minCost2 = dp[i][color];
                    colorOfMinCost2 = color;
                }
            }
        }

        return dp[n][colorOfMinCost1];
    }

    int minCostII(vector<vector<int>>& costs) {
        //return dp1(costs);
        return dp2(costs);
    }
};
