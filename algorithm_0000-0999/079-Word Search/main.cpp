class Solution {
public:
    bool existRecv(vector<vector<char>>& board, size_t r, size_t c, size_t depth, const string& word) {
        assert(depth < word.size());

        if (board[r][c] != word[depth]) {
            return false;
        }
        if (word.size() <= (depth + 1)) {
            return true;
        }

        char ch = board[r][c];

        board[r][c] = '.';
        bool found =
            (0 < c && existRecv(board, r, c - 1, depth + 1, word)) ||
            (0 < r && existRecv(board, r - 1, c, depth + 1, word)) ||
            ((c + 1) < board[0].size() && existRecv(board, r, c + 1, depth + 1, word)) ||
            ((r + 1) < board.size() && existRecv(board, r + 1, c, depth + 1, word));
        board[r][c] = ch;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        size_t row = board.size(), col = board.empty() ? 0 : board.front().size();
        for (size_t r = 0; r < row; ++r) {
            for (size_t c = 0; c < col; ++c) {
                if (existRecv(board, r, c, 0, word)) {
                    return true;
                }
            }
        }

        return false;
    }
};
