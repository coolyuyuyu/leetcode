class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid, size_t row, size_t col) {
        if (grid[row][col] == 0) {
            return 0;
        }

        size_t rowCnt = grid.size();
        size_t colCnt = grid.empty() ? 0 : grid.front().size();
        assert(row < rowCnt && col < colCnt);

        grid[row][col] = 0;
        int area = 1;

        // lft
        if (0 < col) {
            area += maxAreaOfIsland(grid, row, col - 1);
        }

        // top
        if (0 < row) {
            area += maxAreaOfIsland(grid, row - 1, col);
        }

        // rht
        if (col + 1 < colCnt) {
            area += maxAreaOfIsland(grid, row, col + 1);
        }

        // btm
        if (row + 1 < rowCnt) {
            area += maxAreaOfIsland(grid, row + 1, col);
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        size_t rowCnt = grid.size();
        size_t colCnt = grid.empty() ? 0 : grid.front().size();
        for (size_t row = 0; row < rowCnt; ++row) {
            for (size_t col = 0; col < colCnt; ++col) {
                int area = maxAreaOfIsland(grid, row, col);
                if (maxArea < area) {
                    maxArea = area;
                }
            }
        }

        return maxArea;
    }
};