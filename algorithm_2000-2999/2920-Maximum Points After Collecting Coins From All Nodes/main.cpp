class Solution {
public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n = edges.size() + 1;
        vector<int> graph[n];

        for (const auto& edge : edges) {
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        // 10000 >> 13 = 1
        int dp[n][14];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 14; ++j) {
                dp[i][j] = INT_MIN;
            }
        }
        std::function<int(int, int, int)> dfs = [&](int cur, int pre, int reduced) {
            if (dp[cur][reduced] != INT_MIN) {
                return dp[cur][reduced];
            }

            int sum1 = (coins[cur] >> reduced) - k;
            for (int nxt : graph[cur]) {
                if (nxt == pre) { continue; }
                sum1 += dfs(nxt, cur, reduced);
            }

            int sum2 = (coins[cur] >> reduced) / 2;
            for (int nxt : graph[cur]) {
                if (nxt == pre) { continue; }
                sum2 += dfs(nxt, cur, std::min(reduced + 1, 13));
            }

            return dp[cur][reduced] = std::max(sum1, sum2);
        };

        return dfs(0, -1, 0);
    }
};
