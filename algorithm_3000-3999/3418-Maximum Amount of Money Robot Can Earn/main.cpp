class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins.empty() ? 0 : coins[0].size();

        // dp[r][c][k]: the maximum profit the robot can gain when reaching (r, c) with k moves of neutralization.
        int dp[m][n][3];
        std::fill(&(dp[0][0][0]), &(dp[0][0][0]) + m * n * 3, INT_MIN);

        dp[0][0][0] = coins[0][0], dp[0][0][1] = dp[0][0][2] = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                for (int k = 0; k < 3; ++k) {
                    if (r > 0) { dp[r][c][k] = std::max(dp[r][c][k], dp[r - 1][c][k] + coins[r][c]); }
                    if (r > 0 && k > 0) { dp[r][c][k] = std::max(dp[r][c][k], dp[r - 1][c][k - 1]); }
                    if (c > 0) { dp[r][c][k] = std::max(dp[r][c][k], dp[r][c - 1][k] + coins[r][c]); }
                    if (c > 0 && k > 0) { dp[r][c][k] = std::max(dp[r][c][k], dp[r][c - 1][k - 1]); }
                }
            }
        }

        return std::max({dp[m - 1][n - 1][0], dp[m - 1][n - 1][1], dp[m - 1][n - 1][2]});
    }
};
