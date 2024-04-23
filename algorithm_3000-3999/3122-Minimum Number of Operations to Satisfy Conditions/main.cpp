class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        // dp[c][d]: the minimum number of operations needed for columns[0:c], and the value of last column is d
        int dp[n][10];
        for (int c = 0; c < n; ++c) {
            for (int d = 0; d <= 9; ++d) {
                dp[c][d] = INT_MAX;
            }
        }
        for (int d = 0; d <= 9; ++d) {
            dp[0][d] = 0;
            for (int r = 0; r < m; ++r) {
                dp[0][d] += (grid[r][0] != d ? 1 : 0);
            }
        }

        for (int c = 1; c < n; ++c) {
            for (int cur = 0; cur <= 9; ++cur) {
                int cnt = 0;
                for (int r = 0; r < m; ++r) {
                    cnt += (grid[r][c] != cur ? 1 : 0);
                }

                for (int pre = 0; pre <= 9; ++pre) {
                    if (pre == cur) { continue; }
                    dp[c][cur] = std::min(dp[c][cur], dp[c - 1][pre] + cnt);
                }
            }
        }

        int ret = INT_MAX;
        for (int d = 0; d <= 9; ++d) {
            ret = std::min(ret, dp[n - 1][d]);
        }

        return ret;
    }
};
