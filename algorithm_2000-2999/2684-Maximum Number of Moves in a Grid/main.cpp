class Solution {
public:
    int byDFS(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        // dp[r][c]: the length of maximal path to form a serie of moves starting from (r,c)
        int dp[m][n];
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                dp[r][c] = 0;
            }
        }

        vector<pair<int, int>> dirs = {{-1, 1}, {0, 1}, {1, 1}};
        std::function<int(int, int)> dfs = [&](int r, int c) {
            int& ret = dp[r][c];
            if (ret > 0) { return ret; }

            ret = 1;
            for (const auto& [dr, dc] : dirs) {
                int x = r + dr, y = c + dc;
                if (x < 0 || x >= m || y < 0 || y >= n) { continue; }
                if (grid[x][y] <= grid[r][c]) { continue; }
                ret = std::max(ret, 1 + dfs(x, y));
            }

            return ret;
        };

        int ret = 0;
        for (int r = 0; r < m; ++r) {
            ret = std::max(ret, dfs(r, 0));
        }

        return ret - 1;
    }

    int byDP(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        // dp[r][c]: true if (r, c) can be reached from any source
        bool dp[m][n];
        for (int r = 0; r < m; ++r) {
            dp[r][0] = true;
        }

        int ret = 0;
        for (int c = 1; c < n; ++c) {
            for (int r = 0; r < m; ++r) {
                dp[r][c] = false;
                if (!dp[r][c] && r > 0 && dp[r - 1][c - 1] && grid[r - 1][c - 1] < grid[r][c]) { dp[r][c] = true; }
                if (!dp[r][c] && dp[r][c - 1] && grid[r][c - 1] < grid[r][c]) { dp[r][c] = true; }
                if (!dp[r][c] && r + 1 < m && dp[r + 1][c - 1] && grid[r + 1][c - 1] < grid[r][c]) { dp[r][c] = true; }
                if (dp[r][c]) {
                    ret = c;
                }
            }
        }

        return ret;
    }

    int maxMoves(vector<vector<int>>& grid) {
        //return byDFS(grid);
        return byDP(grid);
    }
};
