class Solution {
public:
    long long minCostExcludingMax(int n, vector<vector<int>>& edges) {
        vector<pair<int, int>> graph[n];
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }

        std::function<vector<long long>(int)> dijkstra = [&](int src) {
            vector<long long> dists(n, -1);

            priority_queue<pair<long long, int>, vector<pair<long long ,int>>, std::greater<>> minPQ; // <cost, node>
            minPQ.emplace(0LL, src);
            while (!minPQ.empty()) {
                auto [cost, u] = minPQ.top();
                minPQ.pop();

                if (dists[u] >= 0) { continue; }
                dists[u] = cost;

                for (const auto& [v, w] : graph[u]) {
                    if (dists[v] >= 0) { continue; }
                    minPQ.emplace(cost + w, v);
                }
            }

            return dists;
        };

        auto dists1 = dijkstra(0);
        auto dists2 = dijkstra(n - 1);

        long long ret = LLONG_MAX;
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            ret = std::min({ret, dists1[u] + dists2[v], dists1[v] + dists2[u]});
        }

        return ret;
    }
};
