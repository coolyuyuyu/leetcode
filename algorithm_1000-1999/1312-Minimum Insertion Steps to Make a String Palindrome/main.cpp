class Solution {
public:
    int byDp(string s) {
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

    // Leetcode 1092
    int minLenShortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        str1.insert(str1.begin(), '#');
        str2.insert(str2.begin(), '#');

        // dp[i][j]: the length of shortest common supersequence of str1[1:i] and str2[1:j]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][0] = 0;
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (str1[i] == str2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = std::min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                }
            }
        }

        return dp[m][n];
    }

    int byShortestCommonSupersequence(string s) {
        string t = s;
        std::reverse(t.begin(), t.end());

        return minLenShortestCommonSupersequence(s, t) - s.size();
    }

    int minInsertions(string s) {
        //return byDp(s);
        return byShortestCommonSupersequence(s);
    }
};
