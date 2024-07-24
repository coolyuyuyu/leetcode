class Solution {
public:
    int M = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        int src = 0, dst = n - 1;

        vector<pair<int, int>> graph[n]; // <nxt, w>
        for (const auto& road : roads) {
            int u = road[0], v = road[1], w = road[2];
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }

        vector<long long> dists(n, LLONG_MAX);
        vector<int> cnts(n, 0);
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, std::greater<tuple<long long, int, int>>> pq; // <dist, cur, pre>

        cnts[src] = 1;
        pq.emplace(0, src, -1);
        while (!pq.empty()) {
            auto [dist, cur, pre] = pq.top();
            pq.pop();

            if (dist <= dists[cur]) {
                if (pre >= 0) {
                    cnts[cur] += cnts[pre];
                    cnts[cur] %= M;
                }
            }
            if (dist >= dists[cur]) {
                continue;
            }
            dists[cur] = dist;

            for (const auto& [nxt, w] : graph[cur]) {
                if (dist + w >= dists[nxt]) {
                    if (dist + w == dists[nxt]) {
                        cnts[nxt] += cnts[cur];
                        cnts[nxt] %= M;
                    }
                    continue;
                }
                pq.emplace(dist + w, nxt, cur);
            }
        }

        return cnts[dst];
    }
};
