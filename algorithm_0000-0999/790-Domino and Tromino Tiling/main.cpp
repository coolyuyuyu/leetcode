class Solution {
public:
    int M = 1e9 + 7;

    int dp1(int n) {
        vector<int> dp(1001, 0);
        dp[0] = dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; ++i) {
            for (int j = 0; j + 2 < i; ++j) {
                dp[i] = (dp[i] + (dp[j] * 2) % M) % M;
            }
            dp[i] = (dp[i] + dp[i - 2]) % M;
            dp[i] = (dp[i] + dp[i - 1]) % M;
        }
        return dp[n];
    }

    int dp2(int n) {
        vector<int> dp(1001, 0);
        dp[0] = dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; ++i) {
            dp[i] = (dp[i] + dp[i - 3]) % M;
            dp[i] = (dp[i] + (dp[i - 1] * 2) % M) % M;
        }
        return dp[n];
    }

    int numTilings(int n) {
        // return dp1(n);
        return dp2(n);
    }
};
