class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        if (m < n) {
            return 0;
        }
        if (m == n) {
            return (s == t ? 1 : 0);
        }

        s = "#" + s;
        t = "#" + t;

        // dp[i][j]: the number of distinct subsequences of s[1:i] which equals t[1:j]
        vector<vector<unsigned long>> dp(m + 1, vector<unsigned long>(n + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = 1;
        }
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (s[i] == t[j]) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
            }
        }

        return dp[m][n];
    }
};
