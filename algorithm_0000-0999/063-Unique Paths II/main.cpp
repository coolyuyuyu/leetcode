class Solution {
public:
    // Space: O(m * n)
    int dp1(const vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid.empty() ? 0 : obstacleGrid[0].size();

        // dp[i][j]: the number of possible unique paths that the robot can take to reach (i, j)
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = obstacleGrid[0][0] ? 0 : 1;
        for (int i = 1; i < m; ++i) {
            dp[i][0] = obstacleGrid[i][0] ? 0 : dp[i - 1][0];
        }
        for (int j = 1; j < n; ++j) {
            dp[0][j] = obstacleGrid[0][j] ? 0 : dp[0][j - 1];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = obstacleGrid[i][j] ? 0 : (dp[i - 1][j] + dp[i][j - 1]);
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
        for (int j = 1; j < n; ++j) {
            dp[j] = obstacleGrid[0][j] ? 0 : dp[j - 1];
        }
        for (int i = 1; i < m; ++i) {
            if (obstacleGrid[i][0]) {
                dp[0] = 0;
            }
            for (int j = 1; j < n; ++j) {
                dp[j] = obstacleGrid[i][j] ? 0 : (dp[j] + dp[j - 1]);
            }
        }

        return dp[n - 1];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //return dp1(obstacleGrid);
        return dp2(obstacleGrid);
    }
};
