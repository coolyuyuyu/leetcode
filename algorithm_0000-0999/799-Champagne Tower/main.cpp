class Solution {
public:
    // dp[i][j]: how full the jth glass in the ith row
    double dp[101][101];

    double champagneTower(int poured, int query_row, int query_glass) {
        int m = query_row + 1, n = query_glass + 1;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                dp[r][c] = 0.0;
            }
        }
        dp[0][0] = poured;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < std::min(n, (r + 1)); ++c) {
                if (dp[r][c] <= 1.0) {
                    continue;
                }

                double extraHalf = (dp[r][c] - 1) / 2;
                dp[r + 1][c] += extraHalf;
                dp[r + 1][c + 1] += extraHalf;
                dp[r][c] = 1.0;
            }
        }

        return dp[m - 1][n - 1];
    }
};
