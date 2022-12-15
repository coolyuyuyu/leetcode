class Solution {
public:
    int topdn_dp(const string& s, size_t i, const string& t, size_t j, vector<vector<int>>& cache) {
        if (0 <= cache[i][j]) {
            return cache[i][j];
        }

        if (s[i] == t[j]) {
            cache[i][j] = ((i == 0 || j == 0) ? 0 : topdn_dp(s, i - 1, t, j - 1, cache)) + 1;
        }
        else {
            cache[i][j] = std::max(i == 0 ? 0 : topdn_dp(s, i - 1, t, j, cache), j == 0 ? 0 : topdn_dp(s, i, t, j - 1, cache));
        }

        return cache[i][j];
    }

    int topdn_dp(const string& s, const string& t) {
        size_t m = s.size(), n = t.size();
        if (m == 0 || n == 0) {
            return 0;
        }

        vector<vector<int>> cache(m, vector<int>(n, -1));
        return topdn_dp(s, s.size() - 1, t, t.size() - 1, cache);
    }


    int btmup_dp(const string& s, const string& t) {
        size_t m = s.size(), n = t.size();
        if (m == 0 || n == 0) {
            return 0;
        }

        // dp[i][j]: the length of their longest common subsequence of s[0:i] and t[0:j];
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if (s[i] == t[j]) {
                    dp[i][j] = ((i == 0 || j == 0) ? 0 : dp[i - 1][j - 1]) + 1;
                }
                else {
                    dp[i][j] = std::max(i == 0 ? 0 : dp[i - 1][j], j == 0 ? 0 : dp[i][j - 1]);
                }
            }
        }

        return dp[m - 1][n - 1];
    }

    int longestCommonSubsequence(string text1, string text2) {
        //return topdn_dp(text1, text2);
        return btmup_dp(text1, text2);
    }
};
