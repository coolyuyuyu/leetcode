class Solution {
public:
    void dfs(vector<vector<int>>& grid, size_t row, size_t col, size_t len, size_t& count) {
        switch (grid[row][col]) {
            case 2:
                if (len == 0) {
                    ++count;
                }
                return;
            case 0:
                size_t rowCnt = grid.size(), colCnt = grid.empty() ? 0 : grid.front().size();
                grid[row][col] = -1;

                // lft
                if (0 < col) {
                    dfs(grid, row, col - 1, len - 1, count);
                }

                // upr
                if (0 < row) {
                    dfs(grid, row - 1, col, len - 1, count);
                }

                // rht
                if (col + 1 < colCnt) {
                    dfs(grid, row, col + 1, len - 1, count);
                }

                // btm
                if (row + 1 < rowCnt) {
                    dfs(grid, row + 1, col, len - 1, count);
                }

                grid[row][col] = 0;
                break;
        }
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        size_t rowCnt = grid.size(), colCnt = grid.empty() ? 0 : grid.front().size();

        pair<size_t, size_t> source;
        size_t len = 0;
        for (size_t row = 0; row < rowCnt; ++row) {
            for (size_t col = 0; col < colCnt; ++col) {
                switch (grid[row][col]) {
                    case 0:
                        ++len;
                        break;
                    case 1:
                        source = {row, col};
                        break;
                }
            }
        }

        size_t count = 0;
        grid[source.first][source.second] = 0;
        dfs(grid, source.first, source.second, len + 1, count);
        grid[source.first][source.second] = 1;

        return count;
    }
};