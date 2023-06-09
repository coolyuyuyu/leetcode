class Solution {
public:
    string dp_scs(string str1, string str2) {
        int m = str1.size(), n = str2.size();

        str1 = "#" + str1;
        str2 = "#" + str2;

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

        string ret(dp[m][n], '\0');
        int i = m, j = n, k = ret.size() - 1;
        while (1 <= i && 1 <= j) {
            if (str1[i] == str2[j]) {
                ret[k--] = str1[i];
                --i, --j;
            }
            else if (dp[i][j] == (dp[i - 1][j] + 1)) {
                ret[k--] = str1[i];
                --i;
            }
            else {
                ret[k--] = str2[j];
                --j;
            }
        }
        while (1 <= i) {
            ret[k--] = str1[i--];
        }
        while (1 <= j) {
            ret[k--] = str2[j--];
        }

        return ret;
    }

    string dp_lcs(string str1, string str2) {
        int m = str1.size(), n = str2.size();

        str1 = "#" + str1;
        str2 = "#" + str2;

        // dp[i][j]: the length of longest common subsequence of str1[1:i] and str2[1:j]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][0] = 0;
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = 0;
        }
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (str1[i] == str2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        string ret(m + n - dp[m][n], '\0');
        int i = m, j = n, k = ret.size() - 1;
        while (1 <= i && 1 <= j) {
            if (str1[i] == str2[j]) {
                ret[k--] = str1[i];
                --i, --j;
            }
            else if (dp[i][j] == dp[i - 1][j]) {
                ret[k--] = str1[i];
                --i;
            }
            else {
                ret[k--] = str2[j];
                --j;
            }
        }
        while (1 <= i) {
            ret[k--] = str1[i--];
        }
        while (1 <= j) {
            ret[k--] = str2[j--];
        }

        return ret;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        return dp_scs(str1, str2);
        //return dp_lcs(str1, str2);
    }
};
