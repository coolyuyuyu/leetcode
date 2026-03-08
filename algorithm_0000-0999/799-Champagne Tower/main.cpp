class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        int m = query_row + 1, n = query_glass + 1;

        // dp[i][j]: how full the jth glass in the ith row is
        double dp[m + 1][n + 1];

        std::fill(&dp[0][0], &dp[0][0] + (m + 1) * (n + 1), 0.0 );
        dp[0][0] = poured;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (dp[r][c] <= 1.0) {
                    continue;
                }

                double extraHalf = (dp[r][c] - 1) / 2;
                dp[r + 1][c] += extraHalf;
                dp[r + 1][c + 1] += extraHalf;

                dp[r][c] = 1.0;
            }
        }

        return dp[query_row][query_glass];
    }
};
