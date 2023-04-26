class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // dp[i][j][k]: shortest distance from i to j using vertex 0, 1, ..., k
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX / 2));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 0;
        }
        for (const auto& edge : edges) {
            dp[edge[0]][edge[1]] = edge[2];
            dp[edge[1]][edge[0]] = edge[2];
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
            int cnt = std::count_if(dp[i].begin(), dp[i].end(), [distanceThreshold](int dist) { return dist <= distanceThreshold; });
            if (cnt <= minCnt) {
                minCnt = cnt;
                ret = i;
            }
        }

        return ret;
    }
};
