class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> graph[n];
        for (const auto& edge : edges) {
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
        }

        int status[n]; // -1: none, 0: processing, 1: done and end at destination
        std::fill(status, status + n, -1);
        std::function<bool(int)> dfs = [&](int u) {
            if (graph[u].empty()) {
                return u == destination;
            }
            if (status[u] != -1) {
                return status[u] == 1;
            }

            status[u] = 0;
            for (int v : graph[u]) {
                if (!dfs(v)) {
                    return false;
                }
            }

            status[u] = 1;
            return true;
        };

        return dfs(source);
    }
};
