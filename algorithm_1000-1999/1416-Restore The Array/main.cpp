class Solution {
public:
    int M = 1e9 + 7;

    int numberOfArrays(string s, int k) {
        int n = s.size();
        s.insert(s.begin(), '#');

        int l = ceil(log10(k));

        vector<int> dp(n + 1, 0);  // dp[i] the number of the possible arrays from s[0:i]
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int len = 1, num = 0, base = 1; len <= i && len <= l; ++len, base *= 10) {
                int d = s[i - len + 1] - '0';
                if (d == 0) {
                    continue;
                }

                num += (d * base);
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
