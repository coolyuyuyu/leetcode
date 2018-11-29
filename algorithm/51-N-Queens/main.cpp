class Solution {
public:
    bool checkAllowable(const vector<string>& result, size_t row, size_t col) {
        size_t len = result.size();
        for (size_t r = 0; r < row; ++r) {
            if (result[r][col] == 'Q') {
                return false;
            }
        }

        // top left diagonal
        for (size_t r = row, c = col; 0 < r && 0 < c; --r, --c) {
            if (result[r - 1][c - 1] == 'Q') {
                return false;
            }
        }

        // top right diagonal
        for (size_t r = row, c = col; 0 < r && c + 1 < len; --r, ++c) {
            if (result[r - 1][c + 1] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void solveNQueensRecv(size_t row, vector<string>& result, vector<vector<string>>& results) {
        size_t len = result.size();
        if (len <= row) {
            results.push_back(result);
        }
        else {
            string& line = result[row];
            for (size_t col = 0; col < len; ++col) {
                if (checkAllowable(result, row, col)) {
                    line[col] = 'Q';
                    solveNQueensRecv(row + 1, result, results);
                    line[col] = '.';
                }
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> result(n, string(n, '.'));
        vector<vector<string>> results;
        solveNQueensRecv(0, result, results);
        return results;
    }
};