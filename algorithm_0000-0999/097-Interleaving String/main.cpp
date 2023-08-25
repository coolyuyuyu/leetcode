class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if (m + n != s3.size()) {
            return false;
        }

        s1 = "#" + s1;
        s2 = "#" + s2;
        s3 = "#" + s3;

        // dp[i][j]: whether s3[1:i+j] is formed by an interleaving of s1[1:i] and s2[1:j]
        bool dp[m + 1][n + 1];
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = false;
            }
        }
        dp[0][0] = true;
        for (int i = 1; i <= m && s1[i] == s3[i]; ++i) {
            dp[i][0] = true;
        }
        for (int j = 1; j <= n && s2[j] == s3[j]; ++j) {
            dp[0][j] = true;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dp[i - 1][j] && s1[i] == s3[i + j]) {
                    dp[i][j] = true;
                }
                else if (dp[i][j - 1] && s2[j] == s3[i + j]) {
                    dp[i][j] = true;
                }
            }
        }

        return dp[m][n];
    }
};
