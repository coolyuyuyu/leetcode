class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        // dp[r][c]: the minimum value of (r+1)*(c+1) grid
        int dp[m][n];
        int ret = INT_MIN;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                dp[r][c] = grid[r][c];
                if (r > 0) { dp[r][c] = std::min(dp[r][c], dp[r - 1][c]); }
                if (c > 0) { dp[r][c] = std::min(dp[r][c], dp[r][c - 1]); }

                int ans = INT_MIN;
                if (r > 0) { ret = std::max(ret, grid[r][c] - dp[r - 1][c]); }
                if (c > 0) { ret = std::max(ret, grid[r][c] - dp[r][c - 1]); }
                ret = std::max(ret, ans);
            }
        }

        return ret;
    }
};
