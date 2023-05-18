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

        for (int i = 1; i <= n; ++i) {
            int minVal1 = INT_MAX, colorMin1;
            int minVal2 = INT_MAX, colorMin2;
            for (int color = 0; color < colors; ++color) {
                if (dp[i - 1][color] < minVal1) {
                    minVal2 = minVal1;
                    colorMin2 = colorMin1;
                    minVal1 = dp[i - 1][color];
                    colorMin1 = color;
                }
                else if (dp[i - 1][color] < minVal2) {
                    minVal2 = dp[i - 1][color];
                    colorMin2 = color;
                }
            }

            for (int color = 0; color < colors; ++color) {
                if (color == colorMin1) {
                    dp[i][color] = minVal2 + costs[i][color];
                }
                else {
                    dp[i][color] = minVal1 + costs[i][color];
                }
            }
        }

        int ret = INT_MAX;
        for (int color = 0; color < colors; ++color) {
            ret = std::min(ret, dp[n][color]);
        }

        return ret;
    }

    int minCostII(vector<vector<int>>& costs) {
        //return dp1(costs);
        return dp2(costs);
    }
};
