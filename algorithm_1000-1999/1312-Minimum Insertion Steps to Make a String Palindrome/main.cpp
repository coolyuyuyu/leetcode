class Solution {
public:
    // interval dp
    int dp1(const string& s) {
        int n = s.size();

        // dp[i][j]: the minimum number of steps to make s[i:j] palindrome.
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; ++i) { // len = 1
            dp[i][i] = 0;
        }
        for (int i = 1; i < n; ++i) { // len = 2
            dp[i - 1][i] = (s[i - 1] == s[i] ? 0 : 1);
        }
        for (int len = 3; len <= n; ++len) {
            for (int i = 0, j = i + len - 1; j < n; ++i, ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                }
                else {
                    dp[i][j] = std::min(dp[i + 1][j] + 1, dp[i][j - 1] + 1);
                }
            }
        }

        return dp[0][n - 1];
    }

    int dp2(string s) {
        int n = s.size();

        string t(s.rbegin(), s.rend());
        s = "#" + s;
        t = "#" + t;

        // dp[i][j]: the length of shortest common supersequence of s[1:i] and t[1:j]
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i] == t[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = std::min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                }
            }
        }

        return dp[n][n] - n;
    }

    int minInsertions(string s) {
        //return dp1(s);
        return dp2(s);
    }
};
