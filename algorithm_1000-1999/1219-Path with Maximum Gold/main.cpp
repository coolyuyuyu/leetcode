class Solution {
public:
    int m, n;
    int ids[20][20];

    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int dfs(vector<vector<int>>& grid, int r, int c, int s) {
        if (grid[r][c] == 0) { return 0; }
        int id = ids[r][c];
        if ((s >> id) & 1) { return 0; }
        int t = s | (1 << id);

        int ret = 0;
        for (const auto& [dr, dc] : dirs) {
            int x = r + dr, y = c + dc;
            if (x < 0 || x >= m || y < 0 || y >= n) { continue; }
            ret = std::max(ret, grid[r][c] + dfs(grid, x, y, t));
        }

        return ret;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        for (int r = 0, i = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c]) {
                    ids[r][c] = i++;
                }
            }
        }

        int ret = 0;
        for (int r = 0, i = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                ret = std::max(ret, dfs(grid, r, c, 0));
            }
        }

        return ret;
    }
};
