class Solution {
public:
    int M = 1e9 + 7;

    // Time: O(n * (forget - delay))
    int byUpdateDP(int n, int delay, int forget) {
        // dp[i]: the number of people discovering the secret at i-th day
        int dp[n + 1];
        std::fill(dp, dp + n + 1, 0);
        dp[1] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + delay; j < (i + forget) && j <= n; ++j) {
                dp[j] += dp[i];
                dp[j] %= M;
            }
        }

        int ret = 0;
        for (int i = 1; i <= n; ++i) {
            if ((i + forget) > n) {
                ret += dp[i];
                ret %= M;
            }
        }

        return ret;
    }

    // Time: O(n * (forget - delay))
    int byFillinDP(int n, int delay, int forget) {
        // dp[i]: the number of people discovering the secret at i-th day
        int dp[n + 1];
        std::fill(dp, dp + n + 1, 0);
        dp[1] = 1;

        for (int i = 1; i <= n; ++i) {
            for (int j = i + delay; j < (i + forget) && j <= n; ++j) {
                dp[j] += dp[i];
                dp[j] %= M;
            }
        }

        int ret = 0;
        for (int i = 1; i <= n; ++i) {
            if ((i + forget) > n) {
                ret += dp[i];
                ret %= M;
            }
        }

        return ret;
    }

    // Time: O(n), inspired from UpdateDP
    int byDiffDP(int n, int delay, int forget) {
        // dp[i]: the number of people discovering the secret at i-th day
        int dp[n + 1];
        std::fill(dp, dp + n + 1, 0);

        int diff[n + 1];
        std::fill(diff, diff + n + 1, 0);
        diff[1] += 1;
        diff[2] -= 1;

        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1] + diff[i];
            dp[i] = ((dp[i] % M) + M) % M;
            if (i + delay <= n) {
                diff[i + delay] += dp[i];
            }
            if (i + forget <= n) {
                diff[i + forget] -= dp[i];
            }
        }

        int ret = 0;
        for (int i = 1; i <= n; ++i) {
            if ((i + forget) > n) {
                ret += dp[i];
                ret %= M;
            }
        }

        return ret;
    }

    int peopleAwareOfSecret(int n, int delay, int forget) {
        //return  byUpdateDP(n, delay, forget);
        //return  byFillinDP(n, delay, forget);
        return  byDiffDP(n, delay, forget);
    }
};
