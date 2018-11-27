class Solution {
public:

    void fillWater(int row, int col, vector<vector<char>>& grid) {
        if (grid[row][col] == '0') {
            return;
        }

        grid[row][col] = '0';

        //ltf
        if (0 < col) {
            fillWater(row, col - 1, grid);
        }

        //top
        if (0 < row) {
            fillWater(row - 1, col, grid);
        }

        //rht
        if (col + 1 < grid.front().size()) {
            fillWater(row, col + 1, grid);
        }

        //btm
        if (row + 1 < grid.size()) {
            fillWater(row + 1, col, grid);
        }

    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;

        size_t rowCnt = grid.size();
        size_t colCnt = grid.empty() ? 0 : grid.front().size();
        for (size_t row = 0; row < rowCnt; ++row) {
            for (size_t col = 0; col < colCnt; ++col) {
                if (grid[row][col] == '1') {
                    ++ans;
                    fillWater(row, col, grid);
                }
            }
        }

        return ans;
    }
};