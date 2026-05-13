class Solution {
public:
    int minimumThreshold(int n, vector<vector<int>>& edges, int source, int target, int k) {
        vector<pair<int, int>> graph[n];
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }

        std::function<bool(int)> checkOk = [&](int t) {
            int cnts[n];
            std::fill(cnts, cnts + n, INT_MAX);

            priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<>> pq;
            pq.emplace(0, source);
            while (!pq.empty()) {
                auto [cnt, u] = pq.top();
                pq.pop();

                if (cnt >= cnts[u]) {
                    continue;
                }
                cnts[u] = cnt;
                if (u == target) {
                    break;
                }

                for (const auto& [v, w] : graph[u]) {
                    bool heavy = (w > t);
                    if (cnt + heavy < cnts[v]) {
                        pq.emplace(cnt + heavy, v);
                    }
                }
            }

            return cnts[target] <= k;
        };

        int lo = 0, hi = INT_MAX;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (checkOk(mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return checkOk(lo) ? lo : -1;
    }
};
