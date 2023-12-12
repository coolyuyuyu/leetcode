class Solution {
public:
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        pair<int, int> src;
        for (int r = 0, found = 0; r < m && !found; ++r) {
            for (int c = 0; c < n && !found; ++c) {
                if (grid[r][c] == 1) {
                    found = 1;
                    src = {r, c};
                    break;
                }
            }
        }

        grid[src.first][src.second] = 3;
        queue<pair<int, int>> q1({src});
        queue<pair<int, int>> q2;
        while (!q1.empty()) {
            auto [r, c] = q1.front();
            q1.pop();
            for (const auto& [dr, dc] : dirs) {
                int x = r + dr, y = c + dc;
                if (x < 0 || m <= x || y < 0 || n <= y) { continue; }

                if (grid[x][y] == 0) {
                    grid[x][y] = 2;
                    q2.emplace(x, y);
                }
                else if (grid[x][y] == 1) {
                    grid[x][y] = 3;
                    q1.emplace(x, y);
                }
            }
        }

        for (int ret = 1; !q2.empty(); ++ret) {
            for (int i = q2.size(); 0 < i--;) {
                auto [r, c] = q2.front();
                q2.pop();
                for (const auto& [dr, dc] : dirs) {
                    int x = r + dr, y = c + dc;
                    if (x < 0 || m <= x || y < 0 || n <= y) { continue; }

                    if (grid[x][y] == 1) {
                        return ret;
                    }

                    if (grid[x][y] == 0) {
                        grid[x][y] = 2;
                        q2.emplace(x, y);
                    }
                }
            }
        }

        return -1;
    }
};
