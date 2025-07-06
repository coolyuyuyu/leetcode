class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<tuple<int, int, int>> graph[n];
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], bgn = edge[2], end = edge[3];
            graph[u].emplace_back(v, bgn, end);
        }
        int src = 0, dst = n - 1;

        priority_queue<tuple<int, int>, vector<tuple<int, int>>, std::greater<tuple<int, int>>> pq;
        vector<bool> visited(n, false);

        pq.emplace(0, src);
        while (!pq.empty()) {
            auto [t, u] = pq.top();
            pq.pop();

            if (visited[u]) { continue; }
            visited[u] = true;

            if (u == dst) {
                return t;
            }

            for (const auto& [v, bgn, end] : graph[u]) {
                if (visited[v]) { continue; }
                if (t <= end) {
                    pq.emplace(std::max(bgn + 1, t + 1), v);
                }
            }
        }

        return -1;
    }
};
