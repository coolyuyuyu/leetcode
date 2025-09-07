class Solution {
public:
    int M = 1e9 + 7;
    int uniquePaths(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid.empty() ? 0: grid[0].size();

        // dp[r][c][d]: the number of unique valid paths reach (r,c) and the prev dir == d
        // d = 0: go btm, dp = 1: go rht
        int dp[m][n][2];
        dp[0][0][0] = 1;
        dp[0][0][1] = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (r == 0 && c == 0) { continue; }
                dp[r][c][0] = dp[r][c][1] = 0;
                if (r > 0) {
                    if (grid[r - 1][c] == 0) {
                        dp[r][c][0] += dp[r - 1][c][0];
                        dp[r][c][0] += dp[r - 1][c][1];
                        dp[r][c][0] %= M;
                    }
                    else {
                        dp[r][c][0] += dp[r - 1][c][1];
                    }
                }
                if (c > 0) {
                    if (grid[r][c - 1] == 0) {
                        dp[r][c][1] += dp[r][c - 1][0];
                        dp[r][c][1] += dp[r][c - 1][1];
                        dp[r][c][1] %= M;
                    }
                    else {
                        dp[r][c][1] += dp[r][c - 1][0];
                    }
                }
            }
        }

        return (dp[m - 1][n - 1][0] + dp[m - 1][n - 1][1]) % M;
    }
};
