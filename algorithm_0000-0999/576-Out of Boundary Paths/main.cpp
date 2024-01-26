class Solution {
public:
    int M = 1e9 + 7;

    int dp1(int m, int n, int maxMove, int startRow, int startColumn) {
        // dp[i][j]: the number of paths to move the ball from out of the grid boundary to (i, j)
        int dp[m][n];
        memset(dp, 0, sizeof(dp));
        for (int k = 0; k < maxMove; ++k) {
            int tmp[m][n];
            memcpy(tmp, dp, sizeof(dp));
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    int t = (i == 0 ? 1 : tmp[i - 1][j]);
                    int b = (i + 1 == m ? 1 : tmp[i + 1][j]);
                    int l = (j == 0 ? 1 : tmp[i][j - 1]);
                    int r = (j + 1 == n ? 1 : tmp[i][j + 1]);
                    dp[i][j] = (((t + b) % M + l) % M + r) % M;
                }
            }
        }

        return dp[startRow][startColumn];
    }

    int dp2(int m, int n, int maxMove, int startRow, int startColumn) {
        // dp[i][j]: the number of paths from (startRow, startColumnj to (i, j)
        int dp[m][n];
        memset(dp, 0, sizeof(dp));
        dp[startRow][startColumn] = 1;

        int ret = 0;
        for (int k = 0; k < maxMove; ++k) {
            int tmp[m][n];
            memcpy(tmp, dp, sizeof(dp));
            memset(dp, 0, sizeof(dp));
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    auto& t = (i == 0 ? ret : dp[i - 1][j]);
                    auto& b = (i + 1 == m ? ret : dp[i + 1][j]);
                    auto& l = (j == 0 ? ret : dp[i][j - 1]);
                    auto& r = (j + 1 == n ? ret : dp[i][j + 1]);
                    t = (t + tmp[i][j]) % M;
                    b = (b + tmp[i][j]) % M;
                    l = (l + tmp[i][j]) % M;;
                    r = (r + tmp[i][j]) % M;;
                }
            }
        }

        return ret;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        return dp1(m, n, maxMove, startRow, startColumn);
        //return dp2(m, n, maxMove, startRow, startColumn);
    }
};
