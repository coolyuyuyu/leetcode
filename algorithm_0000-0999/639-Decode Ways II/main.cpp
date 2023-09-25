class Solution {
public:
    int M = 1e9 + 7;

    int numDecodings(string s) {
        int n = s.size();
        s = "#" + s;

        // dp[i]: the number of ways to decode s[1:i]
        long long dp[n + 1];
        dp[0] = 1;
        if (s[1] == '0') {
            dp[1] = 0;
        }
        if ('1' <= s[1] && s[1] <= '9') {
            dp[1] = 1;
        }
        else if (s[1] == '*') {
            dp[1] = 9;
        }
        for (int i = 2; i <= n; ++i) {
            dp[i] = 0;
        }
        for (int i = 2; i <= n; ++i) {
            if (s[i] == '0') {
                if (s[i - 1] == '1' || s[i - 1] == '2') {
                    dp[i] += dp[i - 2];
                }
                else if (s[i - 1] == '*') {
                    dp[i] += 2 * (dp[i - 2]);
                }
            }
            else if ('1' <= s[i] && s[i] <= '9') {
                dp[i] += dp[i - 1];
                if (isdigit(s[i - 1])) {
                    int num = 10 * (s[i - 1] - '0') + (s[i] - '0');
                    if (10 <= num && num <= 26) {
                        dp[i] += dp[i - 2];
                    }
                }
                else {
                    if (s[i] <= '6') {
                        dp[i] += 2 * dp[i - 2];
                    }
                    else {
                        dp[i] += dp[i - 2];
                    }
                }
            }
            else {
                assert(s[i] == '*');
                dp[i] += 9 * dp[i - 1];
                if (s[i - 1] == '1') {
                    dp[i] += 9 * dp[i - 2];
                }
                else if (s[i - 1] == '2') {
                    dp[i] += 6 * dp[i - 2];
                }
                else if (s[i - 1] == '*') {
                    dp[i] += 15 * dp[i - 2];
                }
            }
            dp[i] %= M;
        }

        return dp[n];
    }
};
