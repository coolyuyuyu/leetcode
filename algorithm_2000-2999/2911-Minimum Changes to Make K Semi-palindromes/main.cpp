class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        s = "#" + s;

        // cnt[i][j]: the number of letter changes requried to make s[i:j] to semi-palindrome
        int cnt[n + 1][n + 1];
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                cnt[i][j] = INT_MAX / 2;
                for (int d = 1, len = j - i + 1; d < len; ++d) {
                    if (len % d != 0) { continue; }

                    int sum = 0;
                    for (int delta = 0; delta < d; ++delta) {
                        for (int lft = i + delta, rht = j - d + 1 + delta; lft < rht; lft += d, rht -= d) {
                            if (s[lft] != s[rht]) {
                                ++sum;
                            }
                        }
                    }
                    cnt[i][j] = std::min(cnt[i][j], sum);
                }
            }
        }

        // dp[i][k]: the minimum number of letter changes requried to divide s[1:i] into k semi-palindromic substrings
        int dp[n + 1][k + 1];
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = INT_MAX / 2;
        }
        for (int i = 1; i <= n; ++i) {
            for (int numParts = 1; numParts <= k; ++numParts) {
                dp[i][numParts] = INT_MAX/ 2;
                for (int j = i; numParts <= j; --j) {
                    dp[i][numParts] = std::min(dp[i][numParts], dp[j - 1][numParts - 1] + cnt[j][i]);
                }
            }
        }

        return dp[n][k];
    }
};
