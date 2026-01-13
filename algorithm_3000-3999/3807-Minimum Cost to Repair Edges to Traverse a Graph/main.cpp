class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        vector<pair<int, int>> graph[n];
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }

        std::function<bool(int)> checkOk = [&](int cost) {
            vector<bool> visited(n, false);
            queue<int> q;

            visited[0] = true;
            q.emplace(0);
            for (int d = 0; d <= k && !q.empty(); ++d) {
                for (int i = q.size(); 0 < i--;) {
                    int u = q.front();
                    q.pop();

                    if (u == n - 1) {
                        return true;
                    }

                    for (const auto& [v, w] : graph[u]) {
                        if (w > cost) { continue; }
                        if (visited[v]) { continue; }
                        visited[v] = true;
                        q.emplace(v);
                    }
                }
            }

            return false;
        };
        int lo = 0, hi = 1e9;
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
