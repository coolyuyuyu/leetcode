class Solution {
public:
    int shortestPathWithHops(int n, vector<vector<int>>& edges, int s, int d, int k) {
        vector<pair<int, int>> graph[n];
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }

        int costs[n][k + 1];
        for (int v = 0; v < n; ++v) {
            for (int d = 0; d <= k; ++d) {
                costs[v][d] = INT_MAX;
            }
        }

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, std::greater<tuple<int, int, int>>> pq; // <cost, cur, times>
        pq.emplace(0, s, k);
        while (!pq.empty()) {
            auto [cost, cur, times] = pq.top();
            pq.pop();

            if (cost >= costs[cur][times]) { continue; }
            if (cur == d) {
                return cost;
            }
            costs[cur][times] = cost;

            for (const auto& [nxt, w] : graph[cur]) {
                if (costs[nxt][times] == INT_MAX) {
                    pq.emplace(cost + w, nxt, times);
                }
                if (times > 0 && costs[nxt][times - 1] == INT_MAX) {
                    pq.emplace(cost, nxt, times - 1);
                }
            }
        }

        return -1;
    }
};
