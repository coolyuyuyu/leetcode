class Solution {
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size() + 1;

        vector<pair<int, int>> graph[n];
        for (const auto& edge : edges) {
            int a = edge[0], b = edge[1], w = edge[2];
            graph[a].emplace_back(b, w);
            graph[b].emplace_back(a, w);
        }

        std::function<int(int, int, int)> dfs = [&](int cur, int pre, int sum) {
            int ret = 0;
            if (sum % signalSpeed == 0) {
                ++ret;
            }
            for (const auto& [nxt, w] : graph[cur]) {
                if (nxt == pre) { continue; }
                ret += dfs(nxt, cur, sum + w);
            }

            return ret;
        };

        vector<int> ret(n, 0);
        for (int cur = 0; cur < n; ++cur) {
            vector<int> cnts;
            for (const auto& [nxt, w] : graph[cur]) {
                cnts.push_back(dfs(nxt, cur, w));
            }

            for (int i = 0; i < cnts.size(); ++i) {
                for (int j = i + 1; j < cnts.size(); ++j) {
                    ret[cur] += cnts[i] * cnts[j];
                }
            }
        }

        return ret;
    }
};
