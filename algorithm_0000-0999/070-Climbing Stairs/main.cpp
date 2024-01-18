class Solution {
public:
    // 填表法
    int dp1(int n) {
        // dp[i]: the number of distinct ways to take i steps
        int dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }

    // 刷表法
    int dp2(int n) {
        // dp[i]: the number of distinct ways to take i steps
        int dp[n + 1];
        std::fill(dp, dp + n + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            dp[i + 1] += dp[i];
            if (i + 2 <= n) {
                dp[i + 2] += dp[i];
            }
        }

        return dp[n];
    }

    int climbStairs(int n) {
        //return dp1(n);
        return dp2(n);
    }
};
