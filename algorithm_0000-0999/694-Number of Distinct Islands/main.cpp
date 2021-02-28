class Solution {
public:
    void explore(vector<vector<int>>& grid, size_t row, size_t col, int dir, vector<int>& path) {
        if (grid[row][col] == 0) {
            return;
        }

        grid[row][col] = 0;
        path.emplace_back(dir);

        size_t rowCnt = grid.size(), colCnt = grid.empty() ? 0 : grid.front().size();
        // lft
        if (0 < col) {
            explore(grid, row, col - 1, 1, path);
        }

        // upr
        if (0 < row) {
            explore(grid, row - 1, col, 2, path);
        }

        // rht
        if (col + 1 < colCnt) {
            explore(grid, row, col + 1, 3, path);
        }

        // btm
        if (row + 1 < rowCnt) {
            explore(grid, row + 1, col, 4, path);
        }

        path.emplace_back(0);
    }

    size_t numDistinctIslands(vector<vector<int>>& grid) {
        size_t rowCnt = grid.size(), colCnt = grid.empty() ? 0 : grid.front().size();

        set<vector<int>> paths;
        for (size_t row = 0; row < rowCnt; ++row) {
            for (size_t col = 0; col < colCnt; ++col) {
                if (grid[row][col] == 1) {
                    vector<int> path;
                    explore(grid, row, col, 0, path);
                    paths.insert(path);
                }
            }
        }

        return paths.size();
    }
};