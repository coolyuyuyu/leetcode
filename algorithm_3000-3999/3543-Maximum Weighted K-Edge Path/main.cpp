class Solution {
public:
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        vector<pair<int, int>> graph[n];
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].emplace_back(v, w);
        }

        unordered_map<int, int> dp[n][k + 1];
        std::function<int(int, int, int)> dfs = [&](int cur, int k, int sum) {
            if (k == 0) {
                return (sum < t ? sum : -1);
            }

            if (dp[cur][k].find(sum) != dp[cur][k].end()) {
                return dp[cur][k][sum];
            }

            int& ret = dp[cur][k][sum] = -1;
            for (const auto& [nxt, w] : graph[cur]) {
                ret = std::max(ret, dfs(nxt, k - 1, sum + w));
            }

            return ret;
        };

        int ret = -1;
        for (int cur = 0; cur < n; ++cur) {
            ret = std::max(ret, dfs(cur, k, 0));
        }

        return ret;
    }
};
