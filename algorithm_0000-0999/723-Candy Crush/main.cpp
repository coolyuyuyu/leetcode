class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int m = board.size(), n = board.empty() ? 0 : board[0].size();

        std::function<bool()> mark = [&]() {
            bool found = false;
            for (int r = 0; r < m; ++r) {
                for (int c = 1; c + 1 < n; ++c) {
                    int t = std::abs(board[r][c]);
                    if (t != 0 && std::abs(board[r][c - 1]) == t && t == std::abs(board[r][c + 1])) {
                        board[r][c - 1] = board[r][c] = board[r][c + 1] = -t;
                        found = true;
                    }
                }
            }
            for (int c = 0; c < n; ++c) {
                for (int r = 1; r + 1 < m; ++r) {
                    int t = std::abs(board[r][c]);
                    if (t != 0 && std::abs(board[r - 1][c]) == t && t == std::abs(board[r + 1][c])) {
                        board[r - 1][c] = board[r][c] = board[r + 1][c] = -t;
                        found = true;
                    }
                }
            }
            return found;
        };
        std::function<void()> collapse = [&]() {
            for (int c = 0; c < n; ++c) {
                int i = m - 1;
                for (int r = m - 1; r >= 0; --r) {
                    if (board[r][c] > 0) {
                        board[i--][c] = board[r][c];
                    }
                }
                for (; i >= 0; --i) {
                    board[i][c] = 0;
                }
            }
        };
        while (mark()) {
            collapse();
        }

        return board;
    }
};
