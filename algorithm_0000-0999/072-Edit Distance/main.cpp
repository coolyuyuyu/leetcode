class Solution {
public:
    int minDistance(string word1, string word2) {
        size_t m = word1.size(), n = word2.size();

        // dp[i,j]: distance between word1[0,...,i-1] and word2[0,...,j-1]
        vector<vector<size_t>> dp(m + 1, vector<size_t>(n + 1));
        for (size_t i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }
        for (size_t j = 0; j <= n; ++j) {
            dp[0][j] = j;
        }

        for (size_t i = 1; i <= m; ++i) {
            for (size_t j = 1; j <= n; ++j) {
                dp[i][j] = min(dp[i - 1][j - 1] + (word1[i - 1] == word2[j - 1] ? 0 : 1), min(dp[i - 1][j], dp[i][j - 1]) + 1);
            }
        }

        return dp[m][n];
    }
};