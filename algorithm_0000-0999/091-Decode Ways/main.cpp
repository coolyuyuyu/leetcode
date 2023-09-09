class Solution {
public:
    int dp1(string s) {
        int n = s.size();
        s.insert(s.begin(), '9' + 1);

        // dp[i]: the number of ways to decode it s[1:i]
        int dp[n + 1];
        dp[0] = 1;
        dp[1] = ('1' <= s[1]? 1 : 0);
        for (int i = 2; i <= n; ++i) {
            dp[i] = 0;

            int d1 = s[i] - '0';
            if (1 <= d1) {
                dp[i] += dp[i - 1];
            }
            int d2 = (s[i - 1] - '0') * 10 + s[i] - '0';
            if (10 <= d2 && d2 <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }

    int dp2(string s) {
        int n = s.size();
        s.insert(s.begin(), '9' + 1);

        // dp[i]: the number of ways to decode it s[1:i]
        int dp[n + 1];
        int z = 0; // dp[-1]
        int y = 1; // dp[0]
        int x = ('1' <= s[1]? 1 : 0); // dp[1]
        for (int i = 2; i <= n; ++i) {
            z = y, y = x, x = 0;

            int d1 = s[i] - '0';
            if (1 <= d1) {
                x += y;
            }
            int d2 = (s[i - 1] - '0') * 10 + s[i] - '0';
            if (10 <= d2 && d2 <= 26) {
                x += z;
            }
        }

        return x;
    }

    int numDecodings(string s) {
        return dp1(s);
        // return dp2(s);
    }
};
