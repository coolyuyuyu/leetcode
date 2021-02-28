class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        size_t rowCnt = grid.size();
        size_t colCnt = grid.front().size();

        vector<int> rowHeights(rowCnt);
        for (size_t row = 0; row < rowCnt; ++row) {
            int height = grid[row][0];
            for (size_t col = 1; col < colCnt; ++col) {
                height = max(height, grid[row][col]);
            }
            rowHeights[row] = height;
        }

        vector<int> colHeights(colCnt);
        for (size_t col = 0; col < colCnt; ++col) {
            int height = grid[0][col];
            for (size_t row = 1; row < rowCnt; ++row) {
                height = max(height, grid[row][col]);
            }
            colHeights[col] = height;
        }

        int maxIncrease = 0;
        for (size_t row = 0; row < rowCnt; ++row) {
            for (size_t col = 0; col < colCnt; ++col) {
                int minHeight = min(rowHeights[row], colHeights[col]);
                maxIncrease += (minHeight - grid[row][col]);
            }
        }

        return maxIncrease;
    }
};