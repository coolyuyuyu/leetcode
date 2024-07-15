class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        // dpX[r][c]: the number of X in grid[0][0] - grid[r][c]
        // dpY[r][c]: the number ofYX in grid[0][0] - grid[r][c]
        int dpX[m][n], dpY[m][n];

        int ret = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                dpX[r][c] = (grid[r][c] == 'X' ? 1 : 0);
                dpY[r][c] = (grid[r][c] == 'Y' ? 1 : 0);
                if (r > 0) {
                    dpX[r][c] += dpX[r - 1][c];
                    dpY[r][c] += dpY[r - 1][c];
                }
                if (c > 0) {
                    dpX[r][c] += dpX[r][c - 1];
                    dpY[r][c] += dpY[r][c - 1];
                }
                if (r > 0 && c > 0) {
                    dpX[r][c] -= dpX[r - 1][c - 1];
                    dpY[r][c] -= dpY[r - 1][c - 1];
                }

                if (dpX[r][c] > 0 && dpX[r][c] == dpY[r][c]) {
                    ++ret;
                }
            }
        }

        return ret;
    }
};
