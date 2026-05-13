class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();
        int scores[3] = {0, 1, 2};
        int costs[3] = {0, 1, 1};

        // dp[r][c][w]: the maximum score achivable at (r,c) where total cost = w;
        int dp[m][n][k + 1];
        std::fill(&dp[0][0][0], &dp[0][0][0] + m * n * (k + 1), INT_MIN);
        if (costs[grid[0][0]] <= k) {
            dp[0][0][costs[grid[0][0]]] = scores[grid[0][0]];
        }
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                int score = scores[grid[r][c]], cost = costs[grid[r][c]];
                for (int w = cost; w <= k; ++w) {
                    if (r > 0) {
                        dp[r][c][w] = std::max(dp[r][c][w], dp[r - 1][c][w - cost] + score);
                    }
                    if (c > 0) {
                        dp[r][c][w] = std::max(dp[r][c][w], dp[r][c - 1][w - cost] + score);
                    }
                }
            }
        }

        int ret = -1;
        for (int w = 0; w <= k; ++w) {
            ret = std::max(ret, dp[m - 1][n - 1][w]);
        }

        return ret;
    }
};
