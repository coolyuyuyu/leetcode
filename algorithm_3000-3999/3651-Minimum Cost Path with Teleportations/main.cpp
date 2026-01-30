class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        vector<pair<int, int>> pnts(m * n);
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                pnts[r * n + c] = {r, c};
            }
        }
        std::sort(
            pnts.begin(), pnts.end(),
            [&](const auto& pnt1, const auto& pnt2) {
                const auto& [r1, c1] = pnt1;
                const auto& [r2, c2] = pnt2;
                return grid[r1][c1] > grid[r2][c2];
            });

        // dp[r][c][t]: the min cost to reach (r, c) with at most t teleportations
        int dp[m][n][k + 1];
        dp[0][0][0] = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (r == 0 && c == 0) { continue; }
                dp[r][c][0] = std::min((r > 0 ? dp[r - 1][c][0] : INT_MAX), (c > 0 ? dp[r][c - 1][0] : INT_MAX)) + grid[r][c];
            }
        }

        for (int t = 1; t <= k; ++t) {
            int minCost = INT_MAX / 2;
            for (int i = 0; i < pnts.size();) {
                int j;
                for (j = i; j < pnts.size() && grid[pnts[i].first][pnts[i].second] == grid[pnts[j].first][pnts[j].second]; ++j) {
                    const auto& [r, c] = pnts[j];
                    minCost = std::min(minCost, dp[r][c][t - 1]);
                }
                for (j = i; j < pnts.size() && grid[pnts[i].first][pnts[i].second] == grid[pnts[j].first][pnts[j].second]; ++j) {
                    const auto& [r, c] = pnts[j];
                    dp[r][c][t] = minCost;
                }

                i = j;
            }

            for (int r = 0; r < m; ++r) {
                for (int c = 0; c < n; ++c) {
                    dp[r][c][t] = std::min({
                        dp[r][c][t],
                        (r > 0 ? dp[r - 1][c][t] : INT_MAX / 2) + grid[r][c],
                        (c > 0 ? dp[r][c - 1][t] : INT_MAX / 2) + grid[r][c]});
                }
            }
        }

        int ret = INT_MAX;
        for (int t = 0; t <= k; ++t) {
            ret = std::min(ret, dp[m - 1][n - 1][t]);
        }

        return ret;
    }
};
