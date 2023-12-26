class Solution {
public:
    int M = 1e9 + 7;

    // Time: O(n * k * target), Space: O(n * target)
    int dp1(int n, int k, int target) {
        // dp[i][t]: the number of  ways to roll i dice and the sum up numbers equals t
        int dp[n + 1][target + 1];
        for (int i = 0; i <= n; ++i) {
            for (int t = 0; t <= target; ++t) {
                dp[i][t] = 0;
            }
        }
        dp[0][0] = 1;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                for (int t = j; t <= target; ++t) {
                    dp[i][t] += dp[i - 1][t - j];
                    dp[i][t] %= M;
                }
            }
        }

        return dp[n][target];
    }

    int dp2(int n, int k, int target) {
        // dp[i][t]: the number of  ways to roll i dice and the sum up numbers equals t
        int dp[target + 1];
        for (int t = 0; t <= target; ++t) {
            dp[t] = 0;
        }
        dp[0] = 1;

        for (int i = 1; i <= n; ++i) {
            int tmp[target + 1];
            std::copy(dp, dp + target + 1, tmp);
            std::fill(dp, dp + target + 1, 0);
            for (int j = 1; j <= k; ++j) {
                for (int t = j; t <= target; ++t) {
                    dp[t] += tmp[t - j];
                    dp[t] %= M;
                }
            }
        }

        return dp[target];
    }

    int numRollsToTarget(int n, int k, int target) {
        //return dp1(n, k, target);
        return dp2(n, k, target);
    }
};
