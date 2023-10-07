class Solution {
public:
    int M = 1e9 + 7;
    int numOfArrays(int n, int m, int k) {
        // dp[a][b][c]: the number of ways to build the array arr of a integers with maximum element as b and cost as c
        long dp[n][m + 1][k + 1];
        for (int a = 0; a < n; ++a) {
            for (int b = 0; b <= m; ++b) {
                for (int c = 0; c <= k; ++c) {
                    dp[a][b][c] = 0;
                }
            }
        }
        for (int b = 1; b <= m; ++b) {
            dp[0][b][1] = 1;
        }
        for (int a = 1; a < n; ++a) {
            for (int b = 1; b <= m; ++b) {
                for (int c = 1; c <= k; ++c) {
                    // arr[a] do not incur any search cost;
                    dp[a][b][c] += dp[a - 1][b][c] * b;
                    dp[a][b][c]  %= M;

                    // arr[a] do incur another search cost;
                    for (int x = 1; x < b; ++x) {
                        dp[a][b][c] += dp[a - 1][x][c - 1];
                        dp[a][b][c]  %= M;
                    }
                }
            }
        }

        int ret = 0;
        for (int b = 1; b <= m; ++b) {
            ret += dp[n - 1][b][k];
            ret %= M;
        }

        return ret;
    }
};
