class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        std::function<bool(int, int, char)> checkOk = [&](int r, int c, char d) {
            for (int i = 0; i < 9; ++i) {
                if (board[r][i] == d) {
                    return false;
                }
                if (board[i][c] == d) {
                    return false;
                }
            }

            int i1 = r - r % 3, i2 = i1 + 2;
            int j1 = c - c % 3, j2 = j1 + 2;
            for (int i = i1; i <= i2; ++i) {
                for (int j = j1; j <= j2; ++j) {
                    if (board[i][j] == d) {
                        return false;
                    }
                }
            }

            return true;
        };

        std::function<bool(int, int)> dfs = [&](int r, int c) {
            if (r == 9) { return true; }
            if (c == 9) { return dfs(r + 1, 0); }
            if (board[r][c] != '.') { return dfs(r, c + 1); }

            for (char d = '1'; d <= '9'; ++d) {
                if (checkOk(r, c, d)) {
                    board[r][c] = d;
                    if (dfs(r, c + 1)) {
                        return true;
                    }
                    board[r][c] = '.';
                }
            }

            return false;
        };

        dfs(0, 0);
    }
};
