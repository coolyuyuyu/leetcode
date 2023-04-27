class Solution {
public:
    string dp1_scs(string str1, string str2) {
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

        int i = m, j = n;
        string ret;
        while (1 <= i && 1 <= j) {
            if (str1[i] == str2[j]) {
                ret += str1[i];
                --i, --j;
            }
            else if (dp[i][j] == (dp[i - 1][j] + 1)) {
                ret += str1[i];
                --i;
            }
            else {
                ret += str2[j];
                --j;
            }
        }
        for (; 1 <= i; --i) {
            ret += str1[i];
        }
        for (; 1 <= j; --j) {
            ret += str2[j];
        }
        std::reverse(ret.begin(), ret.end());

        return ret;
    }

    string dp1_lcs(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        str1.insert(str1.begin(), '#');
        str2.insert(str2.begin(), '#');

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

        int i = m, j = n;
        string ret;
        while (1 <= i && 1 <= j) {
            if (str1[i] == str2[j]) {
                ret += str1[i];
                --i, --j;
            }
            else if (dp[i][j] == (dp[i - 1][j])) {
                ret += str1[i];
                --i;
            }
            else {
                ret += str2[j];
                --j;
            }
        }
        for (; 1 <= i; --i) {
            ret += str1[i];
        }
        for (; 1 <= j; --j) {
            ret += str2[j];
        }
        std::reverse(ret.begin(), ret.end());

        return ret;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        //return dp1_scs(str1, str2);
        return dp1_lcs(str1, str2);
    }
};
