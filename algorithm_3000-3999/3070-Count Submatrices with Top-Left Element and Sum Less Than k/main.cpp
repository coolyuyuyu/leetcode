class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        // dp[r][c]: the sum of matrix where top-left is (0,0) and btn-rht is (r,c)
        int dp[m][n];

        int ret = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                dp[r][c] = grid[r][c];
                if (r > 0) {
                    dp[r][c] += dp[r - 1][c];
                }
                if (c > 0) {
                    dp[r][c] += dp[r][c - 1];
                }
                if (r > 0 && c > 0) {
                    dp[r][c] -= dp[r - 1][c - 1];
                }

                if (dp[r][c] <= k) {
                    ++ret;
                }
            }
        }

        return ret;
    }
};
