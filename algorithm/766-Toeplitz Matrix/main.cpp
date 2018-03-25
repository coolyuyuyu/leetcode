class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        size_t rowCnt = matrix.size();
        size_t colCnt = matrix.empty() ? 0 : matrix.front().size();
        for (size_t row = 1; row < rowCnt; ++row) {
            for (size_t col = 1; col < colCnt; ++col) {
                if (matrix[row][col] != matrix[row - 1][col - 1]) {
                    return false;
                }
            }
        }

        return true;
    }
};