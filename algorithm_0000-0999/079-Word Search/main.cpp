class Solution {
public:
    bool existRecv(vector<vector<char>>& board, size_t r, size_t c, const string& word, size_t i) {
        assert(r < board.size() && c < board[0].size());

        if (board[r][c] != word[i]) {
            return false;
        }
        if (word.size() <= (i + 1)) {
            return true;
        }

        char ch = board[r][c];
        board[r][c] = '\0';
        bool found =
            (0 < c && existRecv(board, r, c - 1, word, i + 1)) ||
            (0 < r && existRecv(board, r - 1, c, word, i + 1)) ||
            (c + 1 < board[0].size() && existRecv(board, r, c + 1, word, i + 1)) ||
            (r + 1 < board.size() && existRecv(board, r + 1, c, word, i + 1));
        board[r][c] = ch;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        size_t row = board.size(), col = board[0].size();
        for (size_t r = 0; r < row; ++r) {
            for (size_t c = 0; c < col; ++c) {
                if (existRecv(board, r, c, word, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};
