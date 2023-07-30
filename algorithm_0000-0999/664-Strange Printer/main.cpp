class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        // dp[i][j]: the minimum number of turns to print s[i:j]
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX / 4));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        for (int len = 2; len <= n; ++len) {
            for (int i = 0, j = i + len - 1; j < n; ++i, ++j) {
                dp[i][j] = 1 + dp[i + 1][j];
                for (int k = i + 1; k < j; ++k) {
                    if (s[i] == s[k]) {
                        dp[i][j] = std::min(dp[i][j], dp[i][k - 1] + dp[k + 1][j]);
                    }
                }
                if (s[i] == s[j]) {
                    dp[i][j] = std::min(dp[i][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1];
    }
};

// s[i:j]

// [a..] a {...}
//  i    k    j

// [] a {...}
//    k        k = i

// [a..] a {}
//  i    k     k = j*/
