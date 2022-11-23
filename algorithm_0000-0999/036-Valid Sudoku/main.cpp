class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            vector<bool> row(9, false), col(9, false), box(9, false);
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    if (row[board[i][j] - '0']) {
                        return false;
                    }
                    row[board[i][j] - '0'] = true;
                }

                if (board[j][i] != '.') {
                    if (col[board[j][i] - '0']) {
                        return false;
                    }
                    col[board[j][i] - '0'] = true;
                }

                int row = i / 3 * 3 + j / 3, col = i % 3 * 3 + + j % 3;
                if (board[row][col] != '.') {
                    if (box[board[row][col] - '0']) {
                        return false;
                    }
                    box[board[row][col] - '0'] = true;
                }
            }
        }

        return true;
    }
};
