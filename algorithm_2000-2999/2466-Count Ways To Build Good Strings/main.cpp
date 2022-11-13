class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, 0);
        dp[0] = 1;
        for (size_t i = 1; i <= high; ++i) {
            if (zero <= i) {
                dp[i] = dp[i - zero];
            }
            if (one <= i) {
                dp[i] = (dp[i] + dp[i - one]) % 1000000007;
            }
        }

        int cnt = 0;
        for (size_t i = low; i <= high; ++i) {
            cnt = (cnt + dp[i]) % 1000000007;
        }

        return cnt;
    }
};
