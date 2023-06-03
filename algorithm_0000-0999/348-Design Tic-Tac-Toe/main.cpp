class TicTacToe {
public:
    TicTacToe(int n)
        : m_board(n, vector<int>(n, 0)) {
    }

    int move(int row, int col, int player) {
        m_board[row][col] = player;

        int n = m_board.size();

        bool rowComplete = true, colComplete = true;
        for (int i = 0; i < n; ++i) {
            if (m_board[i][col] != player) {
                colComplete = false;
            }
            if (m_board[row][i] != player) {
                rowComplete = false;
            }
        }
        if (rowComplete || colComplete) {
            return player;
        }

        if (row == col || (row + col + 1) == n) {
            bool diagComplete = true, antidiagComplete = true;
            for (int i = 0; i < n; ++i) {
                if (m_board[i][i] != player) {
                    diagComplete = false;
                }
                if (m_board[i][n - i - 1] != player) {
                    antidiagComplete = false;
                }
            }
            if (diagComplete || antidiagComplete) {
                return player;
            }
        }

        return 0;
    }

private:
    vector<vector<int>> m_board;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
