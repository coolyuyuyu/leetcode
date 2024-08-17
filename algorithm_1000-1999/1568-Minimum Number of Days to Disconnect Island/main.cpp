class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        std::function<int(vector<vector<int>>)> countIslands = [&](vector<vector<int>> grid) {
            vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
            std::function<void(int, int)> dfs = [&](int r, int c) {
                if (r < 0 || r >= m || c < 0 || c >= n) { return; }
                if (grid[r][c] == 0) { return; }
                grid[r][c] = 0;

                for (const auto& [dr, dc] : dirs) {
                    int x = r + dr, y = c + dc;
                    dfs(x, y);
                }
            };

            int ret = 0;
            for (int r = 0; r < m; ++r) {
                for (int c = 0; c < n; ++c) {
                    if (grid[r][c] == 1) {
                        ++ret;
                        dfs(r, c);
                    }
                }
            }

            return ret;
        };

        int cnt = countIslands(grid);
        if (cnt > 1 || cnt == 0) {
            return 0;
        }

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 0) { continue; }

                grid[r][c] = 0;
                int cnt = countIslands(grid);
                if (cnt > 1 || cnt == 0) {
                    return 1;
                }
                grid[r][c] = 1;
            }
        }

        return 2;
    }
};
