class Solution {
public:
    bool checkAllowable(const vector<vector<bool>>& result, size_t row, size_t col) {
        size_t len = result.size();
        for (size_t r = 0; r < row; ++r) {
            if (result[r][col]) {
                return false;
            }
        }

        // top left diagonal
        for (size_t r = row, c = col; 0 < r && 0 < c; --r, --c) {
            if (result[r - 1][c - 1]) {
                return false;
            }
        }

        // top right diagonal
        for (size_t r = row, c = col; 0 < r && c + 1 < len; --r, ++c) {
            if (result[r - 1][c + 1]) {
                return false;
            }
        }

        return true;
    }

    void totalNQueensRecv(size_t row, vector<vector<bool>>& result, int& count) {
        size_t len = result.size();
        if (len <= row) {
            ++count;
        }
        else {
            vector<bool>& line = result[row];
            for (size_t col = 0; col < len; ++col) {
                if (checkAllowable(result, row, col)) {
                    line[col] = true;
                    totalNQueensRecv(row + 1, result, count);
                    line[col] = false;
                }
            }
        }
    }


    int totalNQueens(int n) {
        int count = 0;
        vector<vector<bool>> result(n, vector<bool>(n, false));
        totalNQueensRecv(0, result, count);
        return count;
    }
};