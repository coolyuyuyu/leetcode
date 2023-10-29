class Solution {
public:
    int M = 1e9 + 7;

    // 刷表法
    int dp1(int n) {
        // dp[i][c]: the number of strings of length i and last character is c
        int dp[n + 1][5];
        for (int j = 0; j < 5; ++j) {
            dp[1][j] = 1;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 5; ++j) {
                dp[i + 1][j] = 0;
            }

            dp[i + 1][1] = (dp[i + 1][1] + dp[i][0]) % M;

            dp[i + 1][0] = (dp[i + 1][0] + dp[i][1]) % M;
            dp[i + 1][2] = (dp[i + 1][2] + dp[i][1]) % M;

            dp[i + 1][0] = (dp[i + 1][0] + dp[i][2]) % M;
            dp[i + 1][1] = (dp[i + 1][1] + dp[i][2]) % M;
            dp[i + 1][3] = (dp[i + 1][3] + dp[i][2]) % M;
            dp[i + 1][4] = (dp[i + 1][4] + dp[i][2]) % M;

            dp[i + 1][2] = (dp[i + 1][2] + dp[i][3]) % M;
            dp[i + 1][4] = (dp[i + 1][4] + dp[i][3]) % M;

            dp[i + 1][0] = (dp[i + 1][0] + dp[i][4]) % M;
        }

        int ret = 0;
        for (int j = 0; j < 5; ++j) {
            ret = (ret + dp[n][j]) % M;
        }

        return ret;
    }

    // 填表法
    int dp2(int n) {
        // dp[i][c]: the number of strings of length i and last character is c
        int dp[n + 1][5];
        for (int j = 0; j < 5; ++j) {
            dp[1][j] = 1;
        }
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < 5; ++j) {
                dp[i][j] = 0;
            }
        }
        for (int i = 2; i <= n; ++i) {
            dp[i][0] = (((dp[i - 1][1] + dp[i - 1][2]) % M) + dp[i - 1][4]) % M;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % M;
            dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % M;
            dp[i][3] = (dp[i - 1][2]);
            dp[i][4] = (dp[i - 1][2] + dp[i - 1][3]) % M;
        }

        int ret = 0;
        for (int j = 0; j < 5; ++j) {
            ret = (ret + dp[n][j]) % M;
        }

        return ret;
    }

    int countVowelPermutation(int n) {
        //return dp1(n);
        return dp2(n);
    }
};
