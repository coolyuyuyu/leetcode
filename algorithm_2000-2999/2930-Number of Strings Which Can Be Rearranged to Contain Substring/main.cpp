class Solution {
public:
    int M = 1e9 + 7;

    int stringCount(int n) {
        // dp[i][a][b][c]: the number of good strings of length i containing at least a l, b e and c t

        int dp[n + 1][2][3][2];
        std::memset(dp, 0, sizeof(dp));
        dp[0][0][0][0] = 1;

        for (int i = 1; i <= n; ++i) {
            for (int a = 0; a < 2; ++a) {
                for (int b = 0; b < 3; ++b) {
                    for (int c = 0; c < 2; ++c) {
                        for (char ch = 'a'; ch <= 'z'; ++ch) {
                            if (ch == 'l' && a >= 1) {
                                dp[i][a][b][c] += dp[i - 1][a - 1][b][c];
                            }
                            else if (ch == 'e' && b >= 1) {
                                dp[i][a][b][c] += dp[i - 1][a][b - 1][c];
                            }
                            else if (ch == 't' && c >= 1) {
                                dp[i][a][b][c] += dp[i - 1][a][b][c - 1];
                            }
                            else {
                                dp[i][a][b][c] += dp[i - 1][a][b][c];
                            }
                            dp[i][a][b][c] %= M;
                        }
                    }
                }
            }
        }

        return dp[n][1][2][1];
    }
};
