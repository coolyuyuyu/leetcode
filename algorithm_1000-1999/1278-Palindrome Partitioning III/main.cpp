class Solution {
public:
    int palindromePartition(string s, int k) {
        int n = s.size();

        s = "#" + s;

        // cnts[i][j]: the minimum number of chracter that you need to change to make s[i:j] palindromic
        vector<vector<int>> cnts(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; ++i) { // len = 1
            cnts[i][i] = 0;
        }
        for (int i = 1; (i + 1) <= n; ++i) { // len = 2
            cnts[i][i + 1] = (s[i] == s[i + 1] ? 0 : 1);
        }
        for (int len = 3; len <= n; ++len) {
            for (int i = 1; (i + len - 1) <= n; ++i) {
                int j = i + len - 1;
                cnts[i][j] = cnts[i + 1][j - 1] + (s[i] == s[j] ? 0 : 1);
            }
        }

        // dp[i][numParts]: minimal number of characters that you need to change to divide the s[1:i] into numParts substring.
        vector<vector<int>> dp(n + 1, vector<int>(k + 1));
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = INT_MAX / 2;
        }
        for (int i = 1; i <= n; ++i) {
            for (int numParts = 1; numParts <= std::min(i, k); ++numParts) {
                dp[i][numParts] = INT_MAX / 2;
                for (int j = i; numParts <= j; j--) {
                    dp[i][numParts] = std::min(dp[i][numParts], dp[j - 1][numParts - 1] + cnts[j][i]);
                }
            }
        }

        return dp[n][k];
    }
};
