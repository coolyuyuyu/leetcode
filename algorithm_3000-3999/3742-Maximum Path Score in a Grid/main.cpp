class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();
        int scores[] = {0, 1, 2};
        int costs[] = {0, 1, 1};

        int dp[m][n][k + 1];
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                std::fill(&dp[r][c][0], &dp[r][c][0] + k + 1, INT_MIN);
                int score = scores[grid[r][c]], cost = costs[grid[r][c]];

                if (r == 0 && c == 0) {
                    if (cost <= k) {
                        dp[r][c][cost] = score;
                    }
                    continue;
                }

                if (r > 0) {
                    for (int x = cost; x <= k; ++x) {
                        if (dp[r - 1][c][x - cost] != INT_MIN) {
                            dp[r][c][x] = std::max(dp[r][c][x], dp[r - 1][c][x - cost] + score);
                        }
                    }
                }
                if (c > 0) {
                    for (int x = cost; x <= k; ++x) {
                        if (dp[r][c - 1][x - cost] != INT_MIN) {
                            dp[r][c][x] = std::max(dp[r][c][x], dp[r][c - 1][x - cost] + score);
                        }
                    }
                }
            }
        }

        int ret = -1;
        for (int x = 0; x <= k; ++x) {
            ret = std::max(ret, dp[m - 1][n - 1][x]);
        }

        return ret;
    }
};
