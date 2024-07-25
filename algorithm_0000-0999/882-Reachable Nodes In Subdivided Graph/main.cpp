class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<pair<int, int>> graph[n];
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], cnt = edge[2];
            graph[u].emplace_back(v, cnt + 1);
            graph[v].emplace_back(u, cnt + 1);
        }

        int dists[n];
        std::fill(dists, dists + n, INT_MAX);

        priority_queue<tuple<int, int>, vector<tuple<int, int>>, std::greater<tuple<int, int>>> pq;

        pq.emplace(0, 0);
        while (!pq.empty()) {
            auto [dist, cur] = pq.top();
            pq.pop();

            if (dists[cur] < INT_MAX) { continue; }
            dists[cur] = dist;

            for (const auto& [nxt, w] : graph[cur]) {
                if (dists[nxt] < INT_MAX) { continue; }
                if (dist + w > maxMoves) { continue; }

                pq.emplace(dist + w, nxt);
            }
        }

        int ret = 0;
        for (int v = 0; v < n; ++v) {
            if (dists[v] < INT_MAX) {
                ++ret;
            }
        }

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], cnt = edge[2];
            
            int sum = 0;
            if (dists[u] < INT_MAX) { sum += maxMoves - dists[u]; }
            if (dists[v] < INT_MAX) { sum += maxMoves - dists[v]; }

            ret += std::min(sum, cnt);
        }

        return ret;
    }
};
