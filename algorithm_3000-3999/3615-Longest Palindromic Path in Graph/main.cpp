class Solution {
public:
    int maxLen(int n, vector<vector<int>>& edges, string label) {
        vector<int> graph[n];
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int cache[n][n][1 << n];
        std::fill(&cache[0][0][0], &cache[0][0][0] + n * n * (1 << n), -1);
        std::function<int(int, int, int)> dfs = [&](int u, int v, int mask) {
            if (cache[u][v][mask] >= 0) {
                return cache[u][v][mask];
            }

            int& ret = cache[u][v][mask] = 0;
            for (int x : graph[u]) {
                if (mask & (1 << x)) { continue; }
                for (int y : graph[v]) {
                    if (mask & (1 << y)) { continue; }
                    if (x == y) { continue; }
                    if (label[x] != label[y]) { continue; }
                    ret = std::max(ret, 2 + dfs(x, y, mask | (1 << x) | (1 << y)));
                }
            }

            return ret;
        };

        int ret = 0;
        for (int u = 0; u < n; ++u) {
            ret = std::max(ret, 1 + dfs(u, u, 1 << u));
        }
        for (int u = 0; u < n; ++u) {
            for (int v : graph[u]) {
                if (u > v) { continue; }
                if (label[u] != label[v]) { continue; }
                ret = std::max(ret, 2 + dfs(u, v, (1 << u) | (1 << v)));
            }
        }

        return ret;
    }
};
