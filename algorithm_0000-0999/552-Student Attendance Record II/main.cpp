class Solution {
public:
    int M = 1e9 + 7;

    int checkRecord(int n) {
        // dp[j][k][i]: the length i record with j ABASENT and k consecutive LATE ending at i that make a student eligible
        long long dp[2][3][n + 1];
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                dp[j][k][0] = 0;
            }
        }
        dp[0][0][0] = 1;

        // A, L, P
        for (int i = 1; i <= n; ++i) {
            dp[0][0][i] = (dp[0][0][i - 1] + dp[0][1][i - 1] + dp[0][2][i - 1]) % M;
            dp[0][1][i] = (dp[0][0][i - 1]) % M;
            dp[0][2][i] = (dp[0][1][i - 1]) % M;
            dp[1][0][i] = (dp[0][0][i - 1] + dp[0][1][i - 1] + dp[0][2][i - 1] + dp[1][0][i - 1] + dp[1][1][i - 1] + dp[1][2][i - 1]) % M;
            dp[1][1][i] = (dp[1][0][i - 1]) % M;
            dp[1][2][i] = (dp[1][1][i - 1]) % M;
        }

        int ret = 0;
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                ret += dp[j][k][n];
                ret %= M;
            }
        }

        return ret;
    }
};
