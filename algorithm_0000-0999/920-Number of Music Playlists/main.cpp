class Solution {
public:
    int M = 1e9 + 7;

    int numMusicPlaylists(int n, int goal, int k) {
        // dp[i][j]: the number of playlists of length i using exactly j different songs
        long dp[goal + 1][n + 1];
        dp[0][0] = 1;
        for (int i = 1; i <= goal; ++i) {
            dp[i][0] = 0;
        }
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= goal; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = 0;
                if (j > k) {
                    dp[i][j] += dp[i - 1][j] * (j - k);
                    dp[i][j] %= M;
                }
                if (n > (j - 1)) {
                    dp[i][j] += dp[i - 1][j - 1] * (n - (j - 1));
                    dp[i][j] %= M;
                }

            }
        }

        return dp[goal][n];
    }
};
