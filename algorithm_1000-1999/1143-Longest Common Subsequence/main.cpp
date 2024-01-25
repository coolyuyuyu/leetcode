class Solution {
public:
    int btmup_dp(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        text1 = "#" + text1;
        text2 = "#" + text2;

        // dp[i][j]: the length of their longest common subsequence of text1[:i] and text2[:j]
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
                if (text1[i] == text2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }

    int topdn_dp(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        text1 = "#" + text1;
        text2 = "#" + text2;

        int dp[m + 1][n + 1];
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = -1;
            }
        }
        dp[0][0] = 0;
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = 0;
        }
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = 0;
        }
        std::function<int(int, int)> f = [&](int i, int j) {
            int& ret = dp[i][j];
            if (ret >= 0) {
                return ret;
            }

            if (text1[i] == text2[j]) {
                ret = f(i - 1, j - 1) + 1;
            }
            else {
                ret = std::max(f(i - 1, j), f(i, j - 1));
            }

            return ret;
        };

        return f(m, n);
    }

    int longestCommonSubsequence(string text1, string text2) {
        //return btmup_dp(text1, text2);
        return topdn_dp(text1, text2);
    }
};

