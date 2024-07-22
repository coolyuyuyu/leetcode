class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
        int src = 0, dst = n - 1;

        vector<pair<int, int>> graph[n];
        for (const auto& highway : highways) {
            int u = highway[0], v = highway[1], w = highway[2];
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }

        int costs[n][discounts + 1];
        for (int v = 0; v < n; ++v) {
            for (int d = 0; d <= discounts; ++d) {
                costs[v][d] = INT_MAX;
            }
        }

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, std::greater<tuple<int, int, int>>> pq; // <cost, cur, times>
        pq.emplace(0, src, discounts);
        while (!pq.empty()) {
            auto [cost, cur, times] = pq.top();
            pq.pop();

            if (cost >= costs[cur][times]) { continue; }
            if (cur == dst) {
                return cost;
            }
            costs[cur][times] = cost;

            for (const auto& [nxt, w] : graph[cur]) {
                if (costs[nxt][times] < INT_MAX) { continue; }
                pq.emplace(cost + w, nxt, times);
                if (times > 0) {
                    pq.emplace(cost + w / 2, nxt, times - 1);
                }
            }
        }

        return -1;
    }
};
