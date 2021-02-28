class Solution {
public:
    bool exist(vector<vector<char>>& board, const string& word, size_t index, size_t row, size_t col) {
        ++index;
        if (index >= word.size()) {
            return true;
        }

        char c = board[row][col];
        board[row][col] = NULL;

        bool found =
            (0 < col && word[index] == board[row][col - 1] && exist(board, word, index, row, col - 1)) ||
            (0 < row && word[index] == board[row - 1][col] && exist(board, word, index, row - 1, col)) ||
            (col + 1 < board.front().size() && word[index] == board[row][col + 1] && exist(board, word, index, row, col + 1)) ||
            (row + 1 < board.size() && word[index] == board[row + 1][col] && exist(board, word, index, row + 1, col));

        board[row][col] = c;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        size_t rowCnt = board.size();
        size_t colCnt = board.front().size();
        for (size_t row = 0; row < rowCnt; ++row) {
            for (size_t col = 0; col < colCnt; ++col) {
                if (board[row][col] == word.front()) {
                    if (exist(board, word, 0, row, col)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};