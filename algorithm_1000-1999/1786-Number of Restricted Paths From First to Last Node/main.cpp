class Solution {
public:
    int M = 1e9 + 7;

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& edge : edges) {
            int u = edge[0] - 1, v = edge[1] - 1, w = edge[2];
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }

        std::function<vector<int>(const vector<vector<pair<int, int>>>&, int)> dijkstra = [&](const vector<vector<pair<int, int>>>& graph, int src) {
            vector<int> costs(n, INT_MAX);

            priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
            pq.emplace(0, src);
            while (!pq.empty()) {
                auto [cost, cur] = pq.top();
                pq.pop();

                if (costs[cur] < INT_MAX) {
                    continue;
                }
                costs[cur] = cost;

                for (const auto& [nxt, w] : graph[cur]) {
                    if (costs[nxt] < INT_MAX) {
                        continue;
                    }
                    pq.emplace(cost + w, nxt);
                }
            }

            return costs;
        };
        vector<int> distanceToLastNode = dijkstra(graph, n - 1);

        int cnts[n];
        std::fill(cnts, cnts + n, -1);
        std::function<int(int)> dfs = [&](int cur) {
            if (cur == n - 1) {
                return 1;
            }

            int& cnt = cnts[cur];
            if (cnt != -1) {
                return cnt;
            }

            cnt = 0;
            for (const auto& [nxt, _] : graph[cur]) {
                if (distanceToLastNode[cur] > distanceToLastNode[nxt]) {
                    cnt += dfs(nxt);
                    cnt %= M;
                }
            }

            return cnt;
        };

        return dfs(0);
    }
};
