class Solution {
public:
    // Space: O(m * n)
    int dp1(const vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid.empty() ? 0 : obstacleGrid[0].size();

        // dp[i][j]: the number of possible unique paths that the robot can take to reach (i, j)
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = obstacleGrid[0][0] ? 0 : 1;
        for (int r = 1; r < m; ++r) {
            dp[r][0] = obstacleGrid[r][0] ? 0 : dp[r - 1][0];
        }
        for (int c = 1; c < n; ++c) {
            dp[0][c] = obstacleGrid[0][c] ? 0 : dp[0][c - 1];
        }
        for (int r = 1; r < m; ++r) {
            for (int c = 1; c < n; ++c) {
                dp[r][c] = obstacleGrid[r][c] ? 0 : (dp[r - 1][c] + dp[r][c - 1]);
            }
        }

        return dp[m - 1][n - 1];
    }

    // Space: O(n)
    int dp2(const vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid.empty() ? 0 : obstacleGrid[0].size();

        // dp[i][j]: the number of possible unique paths that the robot can take to reach (i, j)
        vector<int> dp(n);
        dp[0] = obstacleGrid[0][0] ? 0 : 1;
        for (int c = 1; c < n; ++c) {
            dp[c] = obstacleGrid[0][c] ? 0 : dp[c - 1];
        }
        for (int r = 1; r < m; ++r) {
            if (obstacleGrid[r][0]) {
                dp[0] = 0;
            }
            for (int c = 1; c < n; ++c) {
                dp[c] = obstacleGrid[r][c] ? 0 : (dp[c] + dp[c - 1]);
            }
        }

        return dp[n - 1];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //return dp1(obstacleGrid);
        return dp2(obstacleGrid);
    }
};
