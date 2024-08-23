class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();

        // dp[i][j]: the minimum number of turns the printer needed to print s[i:j]
        int dp[n][n];

        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        for (int len = 2; len <= n; ++len) {
            for (int lft = 0, rht = lft + len - 1; rht < n; ++lft, ++rht) {
                // X . . . . . . . .
                dp[lft][rht] = 1 + dp[lft + 1][rht];

                // X . . . X | . . .
                // l         i     r
                for (int i = lft + 1; i < rht; ++i) {
                    if (s[lft] == s[i]) {
                        dp[lft][rht] = std::min(dp[lft][rht], dp[lft][i - 1] + dp[i + 1][rht]);
                    }
                }

                // X . . . . . . . X
                if (s[lft] == s[rht]) {
                    dp[lft][rht] = std::min(dp[lft][rht], dp[lft][rht - 1]);
                }
            }
        }

        return dp[0][n - 1];
    }
};
