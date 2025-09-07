class Solution {
public:
    vector<pair<int, int>> dirs = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        std::function<bool(int, int)> checkInGrid = [&](int r, int c) {
            return 0 <= r && r < m && 0 <= c && c < n;
        };

        int cache[m][n][4][2];
        std::memset(cache, 0, sizeof(cache));
        std::function<int(int, int, int, bool)> dfs = [&](int r, int c, int d1, bool t) {
            if (cache[r][c][d1][t] > 0)  {
                return cache[r][c][d1][t];
            }
            int& ret = cache[r][c][d1][t] = 1;

            int cur = grid[r][c];
            int nxt;
            switch (cur) {
                case 0: nxt = 2; break;
                case 1: nxt = 2; break;
                case 2: nxt = 0; break;
            }

            const auto& [dr1, dc1] = dirs[d1];
            int x1 = r + dr1, y1 = c + dc1;
            if (checkInGrid(x1, y1) && grid[x1][y1] == nxt) {
                ret = std::max(ret, 1 + dfs(x1, y1, d1, t));
            }

            if (t == 0) {
                int d2 = (d1 + 1) % dirs.size();
                const auto& [dr2, dc2] = dirs[d2];
                int x2 = r + dr2, y2 = c + dc2;
                if (checkInGrid(x2, y2) && grid[x2][y2] == nxt) {
                    ret = std::max(ret, 1 + dfs(x2, y2, d2, 1));
                }
            }

            return ret;
        };

        int ret = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] != 1) continue;
                for (int d = 0; d < dirs.size(); ++d) {
                    ret = std::max(ret, dfs(r, c, d, false));
                }
            }
        }

        return ret;
    }
};
