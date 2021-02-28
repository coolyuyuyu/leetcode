class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        size_t rowCnt = matrix.size();
        size_t colCnt = matrix.empty() ? 0 : matrix.front().size();
        if (rowCnt == 0 || colCnt == 0) {
            return false;
        }

        size_t row = 0, col = colCnt - 1;
        while (true) {
            if (matrix[row][col] == target) {
                return true;
            }
            else if (matrix[row][col] < target) {
                ++row;
                if (row >= rowCnt) {
                    return false;
                }
            }
            else {
                if (col == 0) {
                     return false;
                }
                --col;
            }
        }

        assert(false);
    }
};