class Solution {
public:
    vector<pair<int, int>> graph[1000]; //
    long long minCost(int n, vector<int>& appleCost, int k, int src) {
        long long dists[n];
        std::fill(dists, dists + n, LLONG_MAX);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, std::greater<pair<long long, int>>> minPQ; // <dist, node>
        minPQ.emplace(0, src);

        long long ret = LLONG_MAX;
        while (!minPQ.empty()) {
            auto [dist, u] = minPQ.top();
            minPQ.pop();

            if (dists[u] < LLONG_MAX) { continue; }
            if (dist * (k + 1) >= ret) {
                return ret;
            }
            dists[u] = dist;

            ret = std::min(ret, dists[u] * (k + 1) + appleCost[u]);

            for (const auto& [v, cost] : graph[u]) {
                if (dists[v] < LLONG_MAX) { continue; }
                minPQ.emplace(dist + cost, v);
            }
        }

        return ret;
    }

    vector<long long> minCost(int n, vector<vector<int>>& roads, vector<int>& appleCost, int k) {
        for (const auto& road : roads) {
            int a = road[0] - 1, b = road[1] - 1, cost = road[2];
            graph[a].emplace_back(b, cost);
            graph[b].emplace_back(a, cost);
        }

        vector<long long> ret(n);
        for (int src = 0; src < n; ++src) {
            ret[src] = minCost(n, appleCost, k, src);
        }

        return ret;
    }
};
