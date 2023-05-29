class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        word1.insert(word1.begin(), '#');
        word2.insert(word2.begin(), '#');

        // dp[i][j]: the minimum number of operations required to convert word1[1:i] to word2[1:j]
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
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    // {replace, delete, insert}
                    dp[i][j] = std::min({dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1, dp[i][j - 1] + 1});
                }
            }
        }

        return dp[m][n];
    }
};
