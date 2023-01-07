class Solution {
public:
    int M = 1e9 + 7;

    int numberOfPaths(vector<vector<int>>& grid, int K) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(K, 0)));
        dp[0][0][grid[0][0] % K] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < K; ++k) {
                    int t = ((k - grid[i][j]) % K + K) % K;
                    if (0 < i) {
                        dp[i][j][k] += dp[i-1][j][t];
                    }
                    if (0 < j) {
                        dp[i][j][k] += dp[i][j-1][t];
                    }
                    dp[i][j][k] %= M;
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};

// dp[i][j][k] = dp[i-1][j][t] + dp[i][j-1][t]
// t = ((k - grid[i][j]) % K + K) % K

// assume K = 5, grid[i][j] = 3, we are calculating we calculate dp[i][j][2], 
// => we need dp[i-1][j][4] and dp[i][j-1][4]
