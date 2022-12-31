class Solution {
public:
    vector<vector<int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    void dfs(vector<vector<int>>& grid, int r, int c, int len, int& cnt) {
        if (grid[r][c] == 2) {
            if (len == 0) {
                ++cnt;
            }
            return;
        }

        grid[r][c] = -1;
        for (const auto& dir : dirs) {
            int x = r + dir[0], y = c + dir[1];
            if (0 <= x && x < grid.size() && 0 <= y && y < grid[0].size() && grid[x][y] != -1) {
                dfs(grid, x, y, len - 1, cnt);
            }
        }
        grid[r][c] = 0;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        array<int, 2> src;
        int len = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                switch(grid[r][c]) {
                    case 0:
                    case 2:
                        ++len;
                        break;
                    case 1:
                        src = {r, c};
                }
            }
        }

        int ret = 0;
        grid[src[0]][src[1]] = -1;
        dfs(grid, src[0], src[1], len, ret);
        grid[src[0]][src[1]] = 1;

        return ret;
    }
};