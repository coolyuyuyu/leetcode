class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        size_t m = board.size(), n = board.empty() ? 0 : board[0].size();
        auto find = [&]() -> bool {
            bool marked = false;
            for (size_t r = 0; r < m; ++r) {
                for (size_t c = 1; (c + 1) < n; ++c) {
                    int t = abs(board[r][c]);
                    if (t != 0 && abs(board[r][c - 1]) == t && t == abs(board[r][c + 1])) {
                        board[r][c - 1] = board[r][c] = board[r][c + 1] = -t;
                        marked = true;
                    }
                }
            }
            for (size_t c = 0; c < n; ++c) {
                for (size_t r = 1; (r + 1) < m; ++r) {
                    int t = abs(board[r][c]);
                    if (t != 0 && abs(board[r - 1][c]) == t && t == abs(board[r + 1][c])) {
                        board[r - 1][c] = board[r][c] = board[r + 1][c] = -t;
                        marked = true;
                    }
                }
            }

            return marked;
        };
        auto crush = [&]() -> void {
            for (size_t c = 0; c < n; ++c) {
                size_t idx = m;
                for (size_t r = m; 0 < r--;) {
                    if (0 < board[r][c]) {
                        board[--idx][c] = board[r][c];
                    }
                }
                while (0 < idx--) {
                    board[idx][c] = 0;
                }
            }
        };

        while (find()) {
            crush();
        }

        return board;
    }
};
