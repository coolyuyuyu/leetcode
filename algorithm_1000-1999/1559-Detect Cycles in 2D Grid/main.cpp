class Solution {
public:
    vector<pair<int, int>> dirs = {{0, 0}, {0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        bool visited[m][n];
        std::fill(&visited[0][0], &visited[0][0] + m * n, false);

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (visited[r][c]) { continue; }

                queue<tuple<int, int, int>> q;

                visited[r][c] = true;
                q.emplace(r, c, 0);
                while (!q.empty()) {
                    auto [x, y, dIdx1] = q.front();
                    q.pop();

                    for (int dIdx2 = 1; dIdx2 < dirs.size(); ++dIdx2) {
                        const auto& [dr, dc] = dirs[dIdx2];
                        int a = x + dr, b = y + dc;
                        if (dirs[dIdx1].first + dr == 0 && dirs[dIdx1].second + dc == 0) { continue; }
                        if (a < 0 || a >= m || b < 0 || b >= n) { continue; }
                        if (grid[x][y] != grid[a][b]) { continue; }

                        if (visited[a][b]) {
                            return true;
                        }

                        visited[a][b] = true;
                        q.emplace(a, b, dIdx2);
                    }
                }
            }
        }

        return false;
    }
};
