class Solution {
public:
    bool checkSudokuAllowable(const vector<vector<char>>& board, size_t index, char ch) {
        size_t row = index / 9, col = index % 9;

        for (size_t r = 0; r < 9; ++r) {
            if (board[r][col] == ch) {
                return false;
            }
        }

        for (size_t c = 0; c < 9; ++c) {
            if (board[row][c] == ch) {
                return false;
            }
        }

        for (size_t i = 0, r = row - row % 3; i < 3; ++i) {
            for (size_t j = 0, c = col - col % 3; j < 3; ++j) {
                if (board[r + i][c + j] == ch) {
                    return false;
                }
            }
        }

        return true;
    }

    bool solveSudokuRecv(vector<vector<char>>& board, size_t index) {
        if (81 <= index) {
            return true;
        }

        size_t row = index / 9, col = index % 9;
        if (board[row][col] != '.') {
            return solveSudokuRecv(board, index + 1);
        }

        for (char ch = '1'; ch <= '9'; ++ch) {
            if (checkSudokuAllowable(board, index, ch)) {
                board[row][col] = ch;
                if (solveSudokuRecv(board, index + 1)) {
                    return true;
                }
                board[row][col] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuRecv(board, 0);
    }
};