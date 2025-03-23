class Solution {
public:
    int M = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> graph[n];
        for (const auto& road : roads) {
            int u = road[0], v = road[1], t = road[2];
            graph[u].emplace_back(v, t);
            graph[v].emplace_back(u, t);
        }

        int src = 0, dst = n - 1;
        vector<long> dists(n, INT_MAX);
        priority_queue<pair<long, int>, vector<pair<long, int>>, std::greater<pair<long, int>>> pq;
        pq.emplace(0, src);
        while (!pq.empty()) {
            auto [dist, cur] = pq.top();
            pq.pop();

            if (dists[cur] != INT_MAX) { continue; }
            dists[cur] = dist;

            for (const auto& [nxt, w] : graph[cur]) {
                if (dists[nxt] != INT_MAX) { continue; }
                pq.emplace(dist + w, nxt);
            }
        }

        vector<int> cnts(n, -1);
        std::function<int(int)> dfs = [&](int cur) {
            if (cur == 0) { return 1; }
            if (cnts[cur] != -1) { return cnts[cur]; }

            int& ret = cnts[cur] = 0;
            for (const auto& [nxt, w] : graph[cur]) {
                if (dists[cur] - w == dists[nxt]) {
                    ret += dfs(nxt);
                    ret %= M;
                }
            }

            return ret;
        };

        return dfs(dst);
    }
};
