class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        size_t rowCnt = board.size(), colCnt = board.empty() ? 0 : board.front().size();
        bool todo;
        do {
            todo = false;

            // check horizontally
            for (size_t r = 0; r < rowCnt; ++r) {
                for (size_t c = 1; c + 1 < colCnt; ++c) {
                    int v = abs(board[r][c]);
                    if (v != 0 &&
                        abs(board[r][c - 1]) == v &&
                        abs(board[r][c + 1]) == v) {
                        todo = true;
                        board[r][c - 1] = board[r][c] = board[r][c + 1] = -v;
                    }
                }
            }

            // check vertically
            for (size_t c = 0; c < colCnt; ++c) {
                for (size_t r = 1; r + 1 < rowCnt; ++r) {
                    int v = abs(board[r][c]);
                    if (v != 0 &&
                        abs(board[r - 1][c]) == v &&
                        abs(board[r + 1][c]) == v) {
                        todo = true;
                        board[r - 1][c] = board[r][c] = board[r + 1][c] = -v;
                    }
                }
            }

            if (todo) {
                for (size_t c = 0; c < colCnt; ++c) {
                    size_t index = rowCnt;
                    for (size_t r = rowCnt; 0 < r--;) {
                        if (0 < board[r][c]) {
                            board[--index][c] = board[r][c];
                        }
                    }
                    while (0 < index--) {
                        board[index][c] = 0;
                    }
                }
            }
        } while (todo);


        return board;
    }
};