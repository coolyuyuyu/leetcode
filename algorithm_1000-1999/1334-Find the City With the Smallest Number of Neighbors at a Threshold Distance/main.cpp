class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // dp[k][i][j]: shortest distance from i to j using vertex 0, 1, ..., k
        int dp[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = INT_MAX / 2;
            }
            dp[i][i] = 0;
        }
        for (const auto& edge : edges) {
            int from = edge[0], to = edge[1], w = edge[2];
            dp[from][to] = w;
            dp[to][from] = w;
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }

        int ret;
        int minCnt = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int cnt = std::count_if(dp[i], dp[i] + n, [&](int dist) { return dist <= distanceThreshold; });
            if (cnt <= minCnt) {
                ret = i;
                minCnt = cnt;
            }
        }

        return ret;
    }
};
