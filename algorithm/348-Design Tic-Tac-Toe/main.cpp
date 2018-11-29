class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n)
        : m_board(n, vector<int>(n, 0)) {
    }

    /** Player {player} makes a move at ({row}, {col}).
    @param row The row of the board.
    @param col The column of the board.
    @param player The player, can be either 1 or 2.
    @return The current winning condition, can be either:
    0: No one wins.
    1: Player 1 wins.
    2: Player 2 wins. */
    int move(int row, int col, int player) {
        m_board[row][col] = player;


        size_t n = m_board.size();
        bool done;

        // vertical;
        done = true;
        for (size_t r = 0; r < n; ++r) {
            if (m_board[r][col] != player) {
                done = false;
                break;
            }
        }
        if (done) {
            return player;
        }

        // horizontal
        done = true;
        for (size_t c = 0; c < n; ++c) {
            if (m_board[row][c] != player) {
                done = false;
                break;
            }
        }
        if (done) {
            return player;
        }


        if (row == col) {
            done = true;
            for (size_t i = 0; i < n; ++i) {
                if (m_board[i][i] != player) {
                    done = false;
                    break;
                }
            }
            if (done) {
                return player;
            }
        }

        if (row + col + 1 == n) {
            done = true;
            for (size_t i = 0; i < n; ++i) {
                if (m_board[i][n - i - 1] != player) {
                    done = false;
                    break;
                }
            }
            if (done) {
                return player;
            }
        }

        return 0;
    }

private:
    vector<vector<int>> m_board;
};