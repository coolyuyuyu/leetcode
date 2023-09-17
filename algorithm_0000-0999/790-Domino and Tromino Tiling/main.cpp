class Solution {
public:
    int M = 1e9 + 7;

    int dp1(int n) {
        // dp[i]: the number of ways to tile an 2 x i board
        int dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = 0;
            dp[i] = (dp[i] + dp[i-1]) % M;
            dp[i] = (dp[i] + dp[i-2]) % M;
            for (int j = 0; j + 2 < i; ++j) {
                dp[i] = (dp[i] + (2 * dp[j]) % M) % M;
            }
        }

        return dp[n];
    }

    int dp2(int n) {
        // dp[i]: the number of ways to tile an 2 x i board
        int dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = 0;
            dp[i] = (dp[i] + (2 * dp[i-1]) % M) % M;
            dp[i] = (dp[i] + (3 <= i ? dp[i-3] : 0)) % M;
        }

        return dp[n];
    }

    int numTilings(int n) {
        //return dp1(n);
        return dp2(n);
    }
};

// dp[i] = dp[i-1] + dp[i-2] + (dp[i-3] + ... + dp[0]) * 2
//       = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-3] + (dp[i-4] + ... + dp[0]) * 2
//       = dp[i-1] + dp[i-3] + dp[i-2] + dp[i-3] + (dp[i-4] + ... + dp[0]) * 2;
//       = dp[i-1] + dp[i-3] + d[i-1]
//       = dp[i-1] * 2 + dp[i-3]
