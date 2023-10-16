class Solution {
public:
    int M = 1e9 + 7;

    int numWays(int steps, int arrLen) {
        arrLen = std::min(arrLen, steps / 2 + 1);

        //dp[i][pos]: the number of ways such that the pointer is at index pos after exactly i steps
        int dp[steps + 1][arrLen];
        for (int i = 0; i <= steps; ++i) {
            for (int pos = 0; pos < arrLen; ++pos) {
                dp[i][pos] = 0;
            }
        }

        dp[0][0] = 1;
        for (int i = 1; i <= steps; ++i) {
            for (int pos = 0; pos < arrLen; ++pos) {
                if (0 < pos) {
                   dp[i][pos] = (dp[i][pos] + dp[i - 1][pos - 1]) % M;
                }
                dp[i][pos] = (dp[i][pos] + dp[i - 1][pos]) % M;
                if (pos + 1 < arrLen) {
                    dp[i][pos] = (dp[i][pos] + dp[i - 1][pos + 1]) % M;
                }
            }
        }

        return dp[steps][0];
    }
};
