class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();

        // dp[i][j]: the longest palindromic subsequence's length in s[i:j]
        int dp[n][n];
        std::memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        for (int len = 2; len <= n; ++len) {
            for (int i = 0, j = len - 1; j < n; ++i, ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else {
                    dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1];
    }
};
