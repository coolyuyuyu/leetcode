class Solution {
public:
    int M = 1e9 + 7;

    int countGoodStrings(int low, int high, int zero, int one) {
        // dp[i]: the number of different good strings with length i
        vector<int> dp(high + 1);
        dp[0] = 1;
        for (int i = 1; i <= high; ++i) {
            dp[i] = 0;
            if (zero <= i) {
                dp[i] = dp[i - zero];
            }
            if (one <= i) {
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
