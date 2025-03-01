class Solution {
public:
    string dp_scs(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        s1 = "#" + s1;
        s2 = "#" + s2;

        // dp[i][j]: the length of shortest common supersequence of s1[] and s2[]
        int dp[m + 1][n + 1];
        dp[0][0] = 0;
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = std::min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                }
            }
        }

        string ret(dp[m][n], '_');
        int i = m, j = n, k = ret.size() - 1;
        while (i > 0 && j > 0) {
            if (s1[i] == s2[j]) {
                ret[k--] = s1[i];
                --i, --j;
            }
            else if (dp[i][j] == dp[i - 1][j] + 1) {
                ret[k--] = s1[i--];
            }
            else {
                ret[k--] = s2[j--];
            }
        }
        while (i > 0) {
            ret[k--] = s1[i--];
        }
        while (j > 0) {
            ret[k--] = s2[j--];
        }

        return ret;
    }

    string dp_lcs(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        s1 = "#" + s1;
        s2 = "#" + s2;

        // dp[i][j]: the length of longest common subsequence of s1[] and s2[]
        int dp[m + 1][n + 1];
        dp[0][0] = 0;
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = 0;
        }
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        string ret(m + n - dp[m][n], '_');
        int i = m, j = n, k = ret.size() - 1;
        while (i > 0 && j > 0) {
            if (s1[i] == s2[j]) {
                ret[k--] = s1[i];
                --i, --j;
            }
            else if (dp[i][j] == dp[i - 1][j]) {
                ret[k--] = s1[i--];
            }
            else {
                ret[k--] = s2[j--];
            }
        }
        while (i > 0) {
            ret[k--] = s1[i--];
        }
        while (j > 0) {
            ret[k--] = s2[j--];
        }

        return ret;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        //return dp_scs(str1, str2);
        return dp_lcs(str1, str2);
    }
};
