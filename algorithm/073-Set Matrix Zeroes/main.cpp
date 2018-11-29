class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        size_t rowCnt = matrix.size();
        size_t colCnt = matrix.empty() ? 0 : matrix.front().size();

        unordered_set<int> rowIndexes;
        unordered_set<int> colIndexes;
        for (size_t row = 0; row < rowCnt; ++row) {
            for (size_t col = 0; col < colCnt; ++col) {
                if (matrix[row][col] == 0) {
                    rowIndexes.insert(row);
                    colIndexes.insert(col);
                }
            }
        }

        for (int row : rowIndexes) {
            for (size_t col = 0; col < colCnt; ++col) {
                matrix[row][col] = 0;
            }
        }

        for (int col : colIndexes) {
            for (size_t row = 0; row < rowCnt; ++row) {
                matrix[row][col] = 0;
            }
        }
    }
};