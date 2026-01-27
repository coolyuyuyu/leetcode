class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<pair<int, int>> graph[n];
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, 2 * w);
        }

        bool visited[n];
        std::fill(visited, visited + n, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<>> pq; // <dist, node>
        pq.emplace(0, 0);
        while (!pq.empty()) {
            auto [dist, u] = pq.top();
            pq.pop();

            if (visited[u]) { continue; }
            visited[u] = true;

            if (u == n - 1) {
                return dist;
            }

            for (const auto& [v, w] : graph[u]) {
                if (visited[v]) { continue; }
                pq.emplace(dist + w, v);
            }
        }

        return -1;
    }
};
