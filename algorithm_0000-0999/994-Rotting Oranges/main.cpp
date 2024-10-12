class Solution {
public:
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        queue<pair<int, int>> q;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 2) {
                    q.emplace(r, c);
                }
            }
        }

        int ret = 0;
        while (!q.empty()) {
            for (int k = q.size(); k--;) {
                auto [r, c] = q.front();
                q.pop();

                for (const auto& [dr, dc] : dirs) {
                    int x = r + dr, y = c + dc;
                    if (x < 0 || x >= m || y < 0 || y >= n) { continue; }
                    if (grid[x][y] == 0 || grid[x][y] == 2) { continue; }

                    grid[x][y] = 2;
                    q.emplace(x, y);
                }
            }

            if (!q.empty()) {
                ++ret;
            }
        }

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    return -1;
                }
            }
        }

        return ret;
    }
};
