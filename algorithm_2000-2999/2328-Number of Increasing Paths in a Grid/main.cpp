class Solution {
public:
    int M = 1e9 + 7;
    pair<int, int> dirs[4] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    int btmupDP(const vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        pair<int, int> pnts[m * n];
        for (int r = 0, i = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                pnts[i++] = {r, c};
            }
        }
        std::sort(pnts, pnts + m * n, [&](const auto& pnt1, const auto& pnt2) { return grid[pnt1.first][pnt1.second] < grid[pnt2.first][pnt2.second]; });

        // dp[r][c]: the number of strictly increasing paths ending at (r,c)
        int dp[m][n];
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                dp[r][c] = 1;
            }
        }

        int ret = 0;
        for (const auto& [r, c] : pnts) {
            for (const auto& [dr, dc] : dirs) {
                int x = r + dr, y = c + dc;
                if (x < 0 || m <= x || y < 0 || n <= y) { continue; }
                if (grid[r][c] >= grid[x][y]) { continue; }
                dp[x][y] += dp[r][c];
                dp[x][y] %= M;
            }
            ret += dp[r][c];
            ret %= M;
        }

        return ret;
    }

    int topdnDFS(const vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        // dp[r][c]: the number of strictly increasing paths ending at (r,c)
        int dp[m][n];
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                dp[r][c] = 0;
            }
        }
        std::function<int(int, int)> f = [&](int r, int c) {
            int& ret = dp[r][c];
            if (1 <= ret) {
                return ret;
            }

            ret = 1;
            for (const auto& [dr, dc] : dirs) {
                int x = r + dr, y = c + dc;
                if (x < 0 || m <= x || y < 0 || n <= y) { continue; }
                if (grid[r][c] >= grid[x][y]) { continue; }
                ret += f(x, y);
                ret %= M;
            }

            return ret;
        };

        int ret = 0;
        for (int r = 0, i = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                ret += f(r, c);
                ret %= M;
            }
        }

        return ret;
    }

    int countPaths(vector<vector<int>>& grid) {
        return btmupDP(grid);
        //return topdnDFS(grid);
    }
};
