class Solution {
public:
    int M = 1e9 + 7;

    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        // dp[r][c][val]: the number of path to (r,c) and accumulative xor is val
        int dp[m][n][16];
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                for (int val = 0; val < 16; ++val) {
                    dp[r][c][val] = 0;
                }
            }
        }

        dp[0][0][grid[0][0]] = 1;
        for (int r = 1, val = grid[0][0]; r < m; ++r) {
            val ^= grid[r][0];
            dp[r][0][val] = 1;
        }
        for (int c = 1, val = grid[0][0]; c < n; ++c) {
            val ^= grid[0][c];
            dp[0][c][val] = 1;
        }
        for (int r = 1; r < m; ++r) {
            for (int c = 1; c < n; ++c) {
                for (int val = 0; val < 16; ++val) {
                    dp[r][c][grid[r][c] ^ val] += dp[r - 1][c][val];
                    dp[r][c][grid[r][c] ^ val] %= M;
                    dp[r][c][grid[r][c] ^ val] += dp[r][c - 1][val];
                    dp[r][c][grid[r][c] ^ val] %= M;
                }
            }
        }

        return dp[m - 1][n - 1][k];
    }
};
