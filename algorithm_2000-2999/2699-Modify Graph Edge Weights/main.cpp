class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        bool modifiable[n][n];
        std::memset(modifiable, 0, sizeof(modifiable));
        vector<unordered_map<int, int>> graph(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if (w == -1) {
                w = 1;
                modifiable[u][v] = modifiable[v][u] = true;
            }
            graph[u][v] = graph[v][u] = w;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        vector<int> dist1(n, INT_MAX);
        pq.emplace(0, destination);
        while (!pq.empty()) {
            auto [dist, u] = pq.top();
            pq.pop();

            if (dist1[u] < INT_MAX) {
                continue;
            }
            dist1[u] = dist;

            for (const auto& [v, w] : graph[u]) {
                if (dist1[v] < INT_MAX) { continue; }
                pq.emplace(dist + w, v);
            }
        }

        vector<int> dist2(n, INT_MAX);
        pq.emplace(0, source);
        while (!pq.empty()) {
            auto [dist, u] = pq.top();
            pq.pop();

            if (dist2[u] < INT_MAX) {
                continue;
            }
            if (u == destination) {
                if (dist != target) {
                    return {};
                }
                else {
                    break;
                }
            }
            dist2[u] = dist;

            for (auto [v, w] : graph[u]) {
                if (dist2[v] < INT_MAX) { continue; }
                if (modifiable[u][v] && (dist2[u] + w + dist1[v]) < target) {
                    w = target - dist2[u] - dist1[v];
                    graph[u][v] = graph[v][u] = w;
                }
                pq.emplace(dist + w, v);
            }
        }

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (modifiable[u][v]) {
                edge[2] = graph[edge[0]][edge[1]];
            }
        }

        return edges;
    }
};
