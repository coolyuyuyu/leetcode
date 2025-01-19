class Solution {
public:
    vector<pair<int, int>> dirs = {{}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int byBFS(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();
        bool visited[m][n];
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                visited[r][c] = false;
            }
        }

        queue<pair<int, int>> q;
        std::function<void(int, int)> dfs = [&](int r, int c) {
            if (r < 0 || r >= m || c < 0 || c >= n) { return; }
            if (visited[r][c]) { return; }
            visited[r][c] = true;
            
            q.emplace(r, c);

            const auto& [dr, dc] = dirs[grid[r][c]];
            dfs(r + dr, c + dc);
        };
        dfs(0, 0);
        for (int ret = 0; !q.empty(); ++ret) {
            for (int i = q.size(); 0 < i--;) {
                auto [r, c] = q.front();
                q.pop();

                if (r == m - 1 && c == n - 1) {
                    return ret;
                }

                for (int k = 1; k <= 4; ++k) {
                    if (grid[r][c] == k) { continue; }
                    const auto& [dr, dc] = dirs[k];
                    dfs(r + dr, c + dc);
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
            auto [cost, r, c] = pq.top();
            pq.pop();

            if (visited[r][c]) { continue; }
            visited[r][c] = true;

            if (r == m - 1 && c == n - 1) {
                return cost;
            }

            for (int i = 1; i <= 4; ++i) {
                const auto& [dr, dc] = dirs[i];
                int x = r + dr, y = c + dc;
                if (x < 0 || x >= m || y < 0 || y >= n) { continue; }
                if (visited[x][y]) { continue; }
                pq.emplace(cost + (i == grid[r][c] ? 0 : 1), x, y);
            }
        }

        __builtin_unreachable();
        return -1;
    }

    int minCost(vector<vector<int>>& grid) {
        return byBFS(grid);
        //return byDijkstra(grid);
    }
};
