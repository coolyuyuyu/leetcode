class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        // dp[i][j]: the minimum sum of a falling path down at (i,j)
        int dp[n];
        int min1 = INT_MAX, min2 = INT_MAX, idx1 = -1;
        for (int c = 0; c < n; ++c) {
            dp[c] = grid[0][c];

            if (dp[c] <= min1) {
                min2 = min1;
                min1 = dp[c];
                idx1 = c;
            }
            else if (dp[c] < min2) {
                min2 = dp[c];
            }
        }

        for (int r = 1; r < m; ++r) {
            int tmin1 = INT_MAX, tidx1 = -1, tmin2 = INT_MAX;
            for (int c = 0; c < n; ++c) {
                dp[c] = (c != idx1 ? min1 : min2) + grid[r][c];

                if (dp[c] <= tmin1) {
                    tmin2 = tmin1;
                    tmin1 = dp[c];
                    tidx1 = c;
                }
                else if (dp[c] < tmin2) {
                    tmin2 = dp[c];
                }
            }
            min1 = tmin1,
            idx1 = tidx1;
            min2 = tmin2;
        }

        int ret = INT_MAX;
        for (int c = 0; c < n; ++c) {
            ret = std::min(ret, dp[c]);
        }

        return ret;
    }
};
