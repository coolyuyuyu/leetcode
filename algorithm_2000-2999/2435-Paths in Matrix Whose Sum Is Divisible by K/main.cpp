class Solution {
public:
    int M = 1e9 + 7;

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        int dp[m][n][k];
        std::fill(&dp[0][0][0], &dp[0][0][0] + m * n * k, 0);
        dp[0][0][grid[0][0] % k] = 1;
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                for (int z = 0; z < k; ++z) {
                    int r = ((z - grid[x][y]) % k + k) % k;
                    if (x > 0) {
                        dp[x][y][z] += dp[x - 1][y][r];
                        dp[x][y][z] %= M;
                    }
                    if (y > 0) {
                        dp[x][y][z] += dp[x][y - 1][r];
                        dp[x][y][z] %= M;
                    }
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};
