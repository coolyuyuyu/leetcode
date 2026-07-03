class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        int src = 0, dst = n - 1;
        vector<pair<long long, int>> graph[n];

        int lo = INT_MAX, hi = 0;
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if (!online[u] || !online[v]) { continue; }
            graph[u].emplace_back(v, w);
            lo = std::min(lo, w);
            hi = std::max(hi, w);
        }

        std::function<bool(int)> checkScoreGE = [&](int score) {
            vector<long long> dists(n, LLONG_MAX);
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, std::greater<pair<long long, int>>> pq; // dist, v
            pq.emplace(0, src);
            while (!pq.empty()) {
                auto [dist, u] = pq.top();
                pq.pop();

                if (dists[u] < INT_MAX) { continue; }
                dists[u] = dist;

                if (u == dst) {
                    return true;
                }

                for (const auto& [v, w] : graph[u]) {
                    if (w < score) { continue; }
                    if (dists[v] < INT_MAX) { continue; }
                    if (dist + w > k) { continue; }
                    pq.emplace(dist + w, v);
                }
            }

            return false;
        };

        if (!checkScoreGE(lo)) {
            return -1;
        }

        while (lo < hi) {
            int mid = hi - (hi - lo) / 2;
            if (checkScoreGE(mid)) {
                lo = mid;
            }
            else {
                hi = mid - 1;
            }
        }

        return lo;
    }
};
