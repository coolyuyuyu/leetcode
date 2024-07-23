class Solution {
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int, int>>> graph1(n), graph2(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph1[u].emplace_back(v, w);
            graph2[v].emplace_back(u, w);
        }
        
        std::function<vector<long long>(const vector<vector<pair<int, int>>>&, int)> dijkstra = [&](const vector<vector<pair<int, int>>>& graph, int src) {
            vector<long long> costs(n, LLONG_MAX / 3);

            priority_queue<pair<long long, int>, vector<pair<long long, int>>, std::greater<pair<long long, int>>> pq;
            pq.emplace(0LL, src);
            while (!pq.empty()) {
                auto [cost, cur] = pq.top();
                pq.pop();

                if (costs[cur] < LLONG_MAX / 3) {
                    continue;
                }
                costs[cur] = cost;

                for (const auto& [nxt, w] : graph[cur]) {
                    if (costs[nxt] < LLONG_MAX / 3) {
                        continue;
                    }
                    pq.emplace(0LL +cost + w, nxt);
                }
            }

            return costs;
        };
        vector<long long> costs1 = dijkstra(graph1, src1);
        vector<long long> costs2 = dijkstra(graph1, src2);
        vector<long long> costs3 = dijkstra(graph2, dest);


        long long ret = LLONG_MAX / 3;
        for (int i = 0; i < n; ++i) {
            ret = std::min(ret, costs1[i] + costs2[i] + costs3[i]);
        }
        if (ret >= LLONG_MAX / 3) {
            ret = -1;
        }

        return ret;
    }
};
