class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        int src = 0, dst = n - 1;

        vector<int> graph[n];
        for (const auto& edge : edges) {
            int u = edge[0] - 1, v = edge[1] - 1;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int visited[n];
        std::fill(visited, visited + n, 0);
        int dist[n];
        std::fill(dist, dist + n, INT_MIN);

        queue<pair<int, int>> q; // <cur, t>
        dist[src] = 0;
        q.emplace(src, 0);
        while (!q.empty()) {
            auto [u, t] = q.front();
            q.pop();

            int round = t / change;
            if (round % 2 == 0) {
                t += time;
            }
            else {
                t = (round + 1) * change + time;
            }

            for (int v : graph[u]) {
                if (visited[v] >= 2) { continue; }
                if (t <= dist[v]) { continue; }

                ++visited[v];
                dist[v] = t;
                if (visited[v] >= 2 && v == dst) {
                    return t;
                }
                q.emplace(v, t);
            }
        }

        return -1;
    }
};
