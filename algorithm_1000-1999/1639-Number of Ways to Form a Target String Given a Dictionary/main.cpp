class Solution {
public:
    int M = 1e9 + 7;

    int numWays(vector<string>& words, string target) {
        int m = target.size(), n = words.empty() ? 0 : words[0].size();

        target = "#" + target;

        int cnt[n + 1][26];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j < 26; ++j) {
                cnt[i][j] = 0;
            }
        }
        for (const string& word : words) {
            for (int j = 0; j < n; ++j) {
                ++cnt[j + 1][word[j] - 'a'];
            }
        }

        // the number of ways to form target[0:i-1] from all j-char-long prefix of words.
        int dp[m + 1][n + 1];
        dp[0][0] = 1;
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = 0;
        }
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = 1;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = dp[i][j - 1];
                dp[i][j] += 1L * dp[i - 1][j - 1] * cnt[j][target[i] - 'a'] % M;
                dp[i][j] %= M;
            }
        }

        return dp[m][n];
    }
};
