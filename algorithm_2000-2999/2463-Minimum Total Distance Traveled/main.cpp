class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int m = factory.size(), n = robot.size();
        sort(factory.begin(), factory.end());
        sort(robot.begin(), robot.end());

        // dist[i][a][b]
        long long dist[m][n][n];
        for (int i = 0; i < m; ++i) {
            for (int a = 0; a < n; ++a) {
                long long sum = 0;
                for (int b = a; b < n; ++b) {
                    sum += std::abs(factory[i][0] - robot[b]);
                    dist[i][a][b] = sum;
                }
            }
        }

        // dp[i][j]: the minimum cost such that the factory[0:i] cover j robots
        long long dp[m][n + 1];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = LLONG_MAX / 2;
            }
        }
        dp[0][0] = 0;
        for (int j = 1; j <= std::min(factory[0][1], n); ++j) {
            dp[0][j] = dist[0][0][j - 1];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = dp[i - 1][j]; // k = 0
                for (int k = 1; k <= std::min(factory[i][1], j); ++k) {
                    dp[i][j] = std::min(dp[i][j], dp[i - 1][j - k] + dist[i][j - k][j - 1]);
                }
            }
        }

        return dp[m-1][n];
    }
};
