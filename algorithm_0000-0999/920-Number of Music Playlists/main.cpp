class Solution {
public:
    int M = 1e9 + 7;

    int numMusicPlaylists(int n, int goal, int k) {
        // dp[i][j]: the number of playlists of length i using j different songs
        vector<vector<long>> dp(goal + 1, vector<long>(n + 1));
        dp[1][1] = n;
        for (int i = 2; i <= goal; ++i) {
            for (int j = 1; j <= std::min(n, i); ++j) {
                dp[i][j] = dp[i - 1][j] * std::max(j - k, 0) + dp[i - 1][j - 1] * (n - (j - 1));
                dp[i][j] %= M;
            }
        }

        return dp[goal][n];
    }
};
