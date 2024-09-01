class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        bool modifiable[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                modifiable[i][j] = false;
            }
        }

        unordered_map<int, int> graph[n];
        for (const auto& edge : edges) {
            int a = edge[0], b = edge[1], w = edge[2];
            if (w == -1) {
                w = 1;
                modifiable[a][b] = modifiable[b][a] = true;
            }
            graph[a][b] = graph[b][a] = w;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;

        int distsFromDst[n];
        std::fill(distsFromDst, distsFromDst + n, INT_MAX);
        pq.emplace(0, destination);
        while (!pq.empty()) {
            auto [dist, cur] = pq.top();
            pq.pop();

            if (distsFromDst[cur] < INT_MAX) { continue; }
            distsFromDst[cur] = dist;

            for (const auto& [nxt, cost] : graph[cur]) {
                if (distsFromDst[nxt] < INT_MAX) { continue; }
                pq.emplace(dist + cost, nxt);
            }
        }

        int distsFromSrc[n];
        std::fill(distsFromSrc, distsFromSrc + n, INT_MAX);
        pq.emplace(0, source);
        while (!pq.empty()) {
            auto [dist, cur] = pq.top();
            pq.pop();

            if (distsFromSrc[cur] < INT_MAX) { continue; }
            distsFromSrc[cur] = dist;

            if (cur == destination) {
                if (dist != target) {
                    return {};
                }
                break;
            }

            for (const auto& [nxt, cost] : graph[cur]) {
                if (distsFromSrc[nxt] < INT_MAX) { continue; }
                if (modifiable[cur][nxt] && distsFromSrc[cur] + cost + distsFromDst[nxt] < target) {
                    graph[cur][nxt] = graph[nxt][cur]  = target - distsFromSrc[cur]  - distsFromDst[nxt];
                }
                pq.emplace(dist + cost, nxt);
            }
        }

        vector<vector<int>> ret;
        for (auto& edge : edges) {
            int a = edge[0], b = edge[1];
            if (modifiable[a][b]) {
                edge[2] = graph[a][b];
            }
        }

        return edges;
    }
};
