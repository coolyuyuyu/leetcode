class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        int src = 0;

        vector<pair<int, int>> graph[n];
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }

        vector<int> ret(n, -1);

        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
        pq.emplace(0, src);
        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();

            if (ret[u] >= 0) {
                continue;
            }
            ret[u] = cost;

            for (const auto& [v, w] : graph[u]) {
                if (ret[v] >= 0) { continue; }
                if (cost + w >= disappear[v]) { continue; }
                pq.emplace(cost + w, v);
            }
        }

        return ret;
    }
};
