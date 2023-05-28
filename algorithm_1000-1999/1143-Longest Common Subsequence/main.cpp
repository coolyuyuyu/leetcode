class Solution {
public:
    int btmup_dp(string& s1, string& s2) {
        int m = s1.size(), n = s2.size();
        s1 = "#" + s1;
        s2 = "#" + s2;

        // dp[i][j]: the length of longest common subsequence of s1[1:i] and s2[1:j]
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
                if (s1[i] == s2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }

    int topdn_dp(string& s1, string& s2) {
        int m = s1.size(), n = s2.size();
        s1 = "#" + s1;
        s2 = "#" + s2;

        vector<vector<int>> cache(m + 1, vector<int>(n + 1, -1));
        cache[0][0] = 0;
        for (int i = 1; i <= m; ++i) {
            cache[i][0] = 0;
        }
        for (int j = 1; j <= n; ++j) {
            cache[0][j] = 0;
        }
        std::function<int(int, int)> f = [&](int i, int j) {
            int& ret = cache[i][j];
            if (0 <= ret) {
                return ret;
            }

            if (s1[i] == s2[j]) {
                ret = 1 + f(i - 1, j - 1);
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
