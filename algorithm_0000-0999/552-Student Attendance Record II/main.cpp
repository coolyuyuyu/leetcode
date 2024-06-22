class Solution {
public:
    int M = 1e9 + 7;

    int checkRecord(int n) {
        // dp[i][j][k]: the length i record with j ABASENT and k consecutive LATE ending at i that make a student eligible
        long long dp[n + 1][2][3];
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                dp[0][j][k] = 0;
            }
        }
        dp[0][0][0] = 1;

        // A, L, P
        for (int i = 1; i <= n; ++i) {
            dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % M;
            dp[i][0][1] = (dp[i - 1][0][0]) % M;
            dp[i][0][2] = (dp[i - 1][0][1]) % M;
            dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2] + dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][1][2]) % M;
            dp[i][1][1] = (dp[i - 1][1][0]) % M;
            dp[i][1][2] = (dp[i - 1][1][1]) % M;
        }

        int ret = 0;
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                ret += dp[n][j][k];
                ret %= M;
            }
        }

        return ret;
    }
};
