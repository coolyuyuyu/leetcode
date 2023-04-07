class Solution {
public:
    int btmup_dp(string& s1, string& s2) {
        int m = s1.size(), n = s2.size();

        // dp[i][j]: the length of longest common subsequence of s1[0:i] and s2[0:j]
        int dp[m + 1][n + 1];
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = 0;
        }
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = 0;
        }

        s1 = "#" + s1, s2 = "#" + s2;
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

        // cache[i][j]: the length of longest common subsequence of s1[0:i] and s2[0:j]
        int cache[m + 1][n + 1];
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                cache[i][j] = -1;
            }
        }

        s1 = "#" + s1, s2 = "#" + s2;
        std::function<int(int, int)> f = [&s1, &s2, &cache, &f](int i, int j) {
            if (i == 0 || j == 0) {
                return 0;
            }
            if (0 <= cache[i][j]) {
                return cache[i][j];
            }

            int& ret = cache[i][j];
            if (s1[i] == s2[j]) {
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
