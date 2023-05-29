class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if ((s1.size() + s2.size()) != s3.size()) {
            return false;
        }

        int m = s1.size(), n = s2.size();
        s1.insert(s1.begin(), '#');
        s2.insert(s2.begin(), '#');
        s3.insert(s3.begin(), '#');

        // dp[i][j]: whether s3[:i+j] is formed by an interleaving of s1[:i] and s2[j]
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= m && s1[i] == s3[i]; ++i) {
            dp[i][0] = true;
        }
        for (int j = 1; j <= n && s2[j] == s3[j]; ++j) {
            dp[0][j] = true;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s1[i] == s3[i + j] && dp[i - 1][j]) {
                    dp[i][j] = true;
                }
                else if (s2[j] == s3[i + j] && dp[i][j - 1]) {
                    dp[i][j] = true;
                }
            }
        }

        return dp[m][n];
    }
};
