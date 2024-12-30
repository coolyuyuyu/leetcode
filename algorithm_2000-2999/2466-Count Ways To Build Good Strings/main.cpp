class Solution {
public:
    int M = 1e9 + 7;

    int countGoodStrings(int low, int high, int zero, int one) {
        // dp[i]: number of different length i good strings
        int dp[high + 1];
        dp[0] = 1;
        for (int i = 1; i <= high; ++i) {
            dp[i] = 0;
            if (i >= zero) {
                dp[i] += dp[i - zero];
                dp[i] %= M;
            }
            if (i >= one) {
                dp[i] += dp[i - one];
                dp[i] %= M;
            }
        }

        int ret = 0;
        for (int i = low; i <= high; ++i) {
            ret += dp[i];
            ret %= M;
        }

        return ret;
    }
};
