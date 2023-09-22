class Solution {
public:
    int M = 1e9 + 7;

    int numberOfArrays(string s, int k) {
        int n = s.size();
        int kLen = log10(k) + 1;

        s = "#" + s;

        // dp[i] the number of the possible arrays that can be printed as s[1:i]
        int dp[n + 1];
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            dp[i] = 0;
        }

        for (int i = 1; i <= n; ++i) {
            long long num = 0, base = 1;
            for (int len = 1; len <= i && len <= kLen; ++len, base *= 10) {
                int d = s[i - len + 1] - '0';
                if (d == 0) {
                    continue;
                }
                num += d * base;
                if (k < num) {
                    break;
                }

                dp[i] += dp[i - len];
                dp[i] %= M;
            }
        }

        return dp[n];
    }
};
