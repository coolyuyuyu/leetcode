class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        // dp[r][i][j]: the maximum number of cherries collection which two robots reach (r, i) and (r, j)
        int dp[n][n];
        int tmp[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = INT_MIN / 2;
            }
        }
        dp[0][n - 1] = grid[0][0] + grid[0][n - 1];
        for (int r = 1; r < m; ++r) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    tmp[i][j] = dp[i][j];
                    dp[i][j] = INT_MIN / 2;
                }
            }

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (int a = i - 1; a <= i + 1; ++a) {
                        for (int b = j - 1; b <= j + 1; ++b) {
                            if (a < 0 || n <= a || b < 0 || n <= b) { continue; }
                            if (i == j) {
                                dp[i][j] = std::max(dp[i][j], tmp[a][b] + grid[r][i]);
                            }
                            else {
                                dp[i][j] = std::max(dp[i][j], tmp[a][b] + grid[r][i] + grid[r][j]);
                            }
                        }
                    }
                }
            }
        }

        int ret = INT_MIN;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ret = std::max(ret, dp[i][j]);
            }
        }

        return ret;
    }
};
