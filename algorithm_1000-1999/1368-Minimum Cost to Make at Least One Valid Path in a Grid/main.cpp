class Solution {
public:
    vector<pair<int, int>> dirs = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int byBFS(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();
        bool visited[m][n];
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                visited[r][c] = false;
            }
        }

        std::function<void(int, int, queue<pair<int, int>>&)> dfs = [&](int r, int c, queue<pair<int, int>>& nodes) {
            if (r < 0 || r >= m || c < 0 || c >= n) { return; }
            if (visited[r][c]) { return; }
            visited[r][c] = true;

            nodes.emplace(r, c);

            const auto& [dr, dc] = dirs[grid[r][c]];
            dfs(r + dr, c + dc, nodes);
        };

        queue<pair<int, int>> nodes;
        dfs(0, 0, nodes);
        for (int ret = 0; ; ++ret) {
            for (int x = nodes.size(); 0 < x--;) {
                auto [r, c] = nodes.front();
                nodes.pop();

                if (r == m - 1 && c == n - 1) {
                    return ret;
                }

                for (int i = 1; i <= 4; ++i) {
                    if (grid[r][c] == i) { continue; }
                    const auto& [dr, dc] = dirs[i];
                    dfs(r + dr, c + dc, nodes);
                }
            }
        }

        __builtin_unreachable();
        return -1;
    }

    int byDijkstra(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();
        bool visited[m][n];
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                visited[r][c] = false;
            }
        }
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, std::greater<tuple<int, int, int>>> pq;

        pq.emplace(0, 0, 0);
        while (!pq.empty()) {
            auto [dist, r, c] = pq.top();
            pq.pop();

            if (visited[r][c]) { continue; }
            visited[r][c] = true;

            if (r == m - 1  && c == n - 1) {
                return dist;
            }

            for (int i = 1; i <= 4; ++i) {
                const auto& [dr, dc] = dirs[i];
                int x = r + dr, y = c + dc;
                if (x < 0 || x >= m || y < 0 || y >= n) { continue; }
                if (visited[x][y]) { continue; }

                pq.emplace(dist + (i == grid[r][c] ? 0 : 1), x, y);
            }
        }

        __builtin_unreachable();
        return -1;
    }

    int minCost(vector<vector<int>>& grid) {
        //return byBFS(grid);
        return byDijkstra(grid);
    }
};
