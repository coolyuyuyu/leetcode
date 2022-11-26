class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        size_t rowCnt = grid.size(), colCnt = grid.empty() ? 0 : grid.front().size();

        vector<int> onesRow(rowCnt, 0);
        for (size_t r = 0; r < rowCnt; ++r) {
            for (size_t c = 0; c < colCnt; ++c) {
                if (grid[r][c]) {
                    ++onesRow[r];
                }
            }
        }

        vector<int> onesCol(colCnt, 0);
        for (size_t c = 0; c < colCnt; ++c) {
            for (size_t r = 0; r < rowCnt; ++r) {
                if (grid[r][c]) {
                    ++onesCol[c];
                }
            }
        }

        for (size_t r = 0; r < rowCnt; ++r) {
            for (size_t c = 0; c < colCnt; ++c) {
                grid[r][c] = (onesRow[r] + onesCol[c]) * 2 - rowCnt - colCnt;
            }
        }

        return grid;
    }
};
