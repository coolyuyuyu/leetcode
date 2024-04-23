class Solution {
public:
    vector<int> dijkstra(int n, vector<pair<int, int>> graph[], int src) {
        vector<int> dists(n, INT_MAX / 3);

        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
        pq.emplace(0, src);
        while (!pq.empty()) {
            auto [dist, u] = pq.top();
            pq.pop();

            if (dists[u] != INT_MAX / 3) { continue; }
            dists[u] = dist;

            for (const auto& [v, w] : graph[u]) {
                if (dists[v] != INT_MAX / 3) { continue; }
                pq.emplace(dist + w, v);
            }
        }

        return dists;
    }

    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        int src = 0, dst = n - 1;

        vector<pair<int, int>> graph[n];
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }

        vector<int> dists1 = dijkstra(n, graph, src);
        vector<int> dists2 = dijkstra(n, graph, dst);

        vector<bool> ret(m);
        for (int i = 0; i < m; ++i) {
            const auto& edge = edges[i];
            int u = edge[0], v = edge[1], w = edge[2];
            if (dists1[u] + w + dists2[v] == dists1[dst] || dists1[v] + w + dists2[u] == dists1[dst]) {
                ret[i] = true;
            }
        }

        return ret;
    }
};
