class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();

        //dp[i][j]: the minimum number of steps to make s[i:j] palindrome
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; ++i) { // len = 1
            dp[i][i] = 0;
        }
        for (int i = 0; (i + 1) < n; ++i) { // len = 2
            dp[i][i + 1] = (s[i] == s[i + 1] ? 0 : 1);
        }
        for (int len = 2; len <= n; ++len) {
            for (int i = 0, j = i + len - 1; j < n; ++i, ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                }
                else {
                    dp[i][j] = std::min(dp[i + 1][j], dp[i][j - 1]) + 1;
                }
            }
        }

        return dp[0][n - 1];
    }
};
