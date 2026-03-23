class Solution {
public:
    int M = 1e9 + 7;
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        // dp[r][c]: the minimal and maximal product along the path to (r, c)
        pair<long long, long long> dp[m][n];
        dp[0][0] = {grid[0][0], grid[0][0]};
        for (int r = 1; r < m; ++r) {
            const auto& [minT, maxT] = dp[r - 1][0];
            dp[r][0] = {minT * grid[r][0], maxT * grid[r][0]};
        }
        for (int c = 1; c < n; ++c) {
            const auto& [minL, maxL] = dp[0][c - 1];
            dp[0][c] = {minL * grid[0][c], maxL * grid[0][c]};
        }

        for (int r = 1; r < m; ++r) {
            for (int c = 1; c < n; ++c) {
                const auto& [minT, maxT] = dp[r - 1][c];
                const auto& [minL, maxL] = dp[r][c - 1];
                dp[r][c] = std::minmax({minT * grid[r][c], maxT * grid[r][c], minL * grid[r][c], maxL * grid[r][c]});
            }
        }

        auto [_, ret] = dp[m - 1][n - 1];
        if (ret < 0) {
            ret = -1;
        }
        ret %= 1'000'000'007;

        return ret;
    }
};
