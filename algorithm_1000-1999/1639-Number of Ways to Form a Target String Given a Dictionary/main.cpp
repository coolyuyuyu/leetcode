class Solution {
public:
    int M = 1e9 + 7;

    int numWays(vector<string>& words, string target) {
        int m = target.size();
        int n = words.empty() ? 0 : words[0].size();

        target.insert(target.begin(), '#');

        vector<array<int, 26>> count(n + 1);
        for (const string& word : words) {
            for (int j = 0; j < n; ++j) {
                ++count[j + 1][word[j] - 'a'];
            }
        }

        // dp[i][j]: the number of ways to form target[0:i] from all words[0:j]
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1));
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = 1;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = dp[i][j - 1];
                if (0 < count[j][target[i] - 'a']) {
                    dp[i][j] += (dp[i - 1][j - 1] * count[j][target[i] - 'a']);
                    dp[i][j] %= M;
                }
            }
        }

        return dp[m][n];
    }
};
