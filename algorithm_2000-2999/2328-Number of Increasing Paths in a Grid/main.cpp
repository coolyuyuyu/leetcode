class Solution {
public:
    int M = 1e9 + 7;

    const vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    int btmupDP(const vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        vector<tuple<int, int, int>> arr;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                arr.emplace_back(r, c, grid[r][c]);
            }
        }
        std::sort(arr.begin(), arr.end(), [](const auto& t1, const auto& t2) { return std::get<2>(t1) < std::get<2>(t2); });

        // dp[r][c]: the number of strictly increasing paths ending at matrix (r, c)
        vector<vector<int>> dp(m, vector<int>(n));

        int ret = 0;
        for (const auto& [r, c, v] : arr) {
            dp[r][c] = 1;
            for (const auto& [dr, dc] : dirs) {
                int x = r + dr, y = c + dc;
                if (x < 0 || m <= x || y < 0 || n <= y) {
                    continue;
                }
                if (grid[r][c] <= grid[x][y]) {
                    continue;
                }
                dp[r][c] += dp[x][y];
                dp[r][c] %= M;
            }

            ret += dp[r][c];
            ret %= M;
        }

        return ret;
    }

    int topdnDFS(const vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        // dp[r][c]: the number of strictly increasing paths ending at matrix (r, c)
        vector<vector<int>> dp(m, vector<int>(n, 0));
        std::function<int(int, int)> f = [&](int r, int c) {
            if (0 < dp[r][c]) {
                return dp[r][c];
            }

            int& ret = dp[r][c];
            ret = 1;
            for (const auto& [dr, dc] : dirs) {
                int x = r + dr, y = c + dc;
                if (x < 0 || m <= x || y < 0 || n <= y) {
                    continue;
                }
                if (grid[r][c] <= grid[x][y]) {
                    continue;
                }

                ret += f(x, y);
                ret %= M;
            }

            return ret;
        };

        int ret = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                ret += f(r, c);
                ret %= M;
            }
        }

        return ret;
    }

    int countPaths(vector<vector<int>>& grid) {
        //return btmupDP(grid);
        return topdnDFS(grid);
    }
};
