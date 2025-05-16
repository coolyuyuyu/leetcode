class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        int lft[m][n], rht[m][n];
        for (int r = 0; r < m; ++r) {
            lft[r][0] = (grid[r][0] == 'E' ? 1 : 0);
            for (int c = 1; c < n; ++c) {
                switch (grid[r][c]) {
                    case 'W': lft[r][c] = 0; break;
                    case 'E': lft[r][c] = lft[r][c - 1] + 1; break;
                    case '0': lft[r][c] = lft[r][c - 1]; break;
                }
            }

            rht[r][n - 1] = (grid[r][n - 1] == 'E' ? 1 : 0);
            for (int c = n - 2; c >= 0; --c) {
                switch (grid[r][c]) {
                    case 'W': rht[r][c] = 0; break;
                    case 'E': rht[r][c] = rht[r][c + 1] + 1; break;
                    case '0': rht[r][c] = rht[r][c + 1]; break;
                }
            }
        }

        int top[m][n], btm[m][n];
        for (int c = 0; c < n; ++c) {
            top[0][c] = (grid[0][c] == 'E' ? 1 : 0);
            for (int r = 1; r < m; ++r) {
                switch (grid[r][c]) {
                    case 'W': top[r][c] = 0; break;
                    case 'E': top[r][c] = top[r - 1][c] + 1; break;
                    case '0': top[r][c] = top[r - 1][c]; break;
                }
            }

            btm[m - 1][c] = (grid[m - 1][c] == 'E' ? 1 : 0);
            for (int r = m - 2; r >= 0; --r) {
                switch (grid[r][c]) {
                    case 'W': btm[r][c] = 0; break;
                    case 'E': btm[r][c] = btm[r + 1][c] + 1; break;
                    case '0': btm[r][c] = btm[r + 1][c]; break;
                }
            }
        }

        int ret = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] != '0') { continue; }
                ret = std::max(ret, lft[r][c] + rht[r][c] + top[r][c] + btm[r][c]);
            }
        }

        return ret;
    }
};
