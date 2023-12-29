class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        string t(s.rbegin(), s.rend());

        int n = s.size();
        s = "#" + s;
        t = "#" + t;

        // dp[i][j]: the length of longest common subsequence of s[1:i] and t[1:j]
        int dp[n + 1][n + 1];
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = 0;
        }
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i] == t[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return n - dp[n][n] <= k;
    }
};
