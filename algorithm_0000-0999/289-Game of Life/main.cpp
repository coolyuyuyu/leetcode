class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board.empty() ? 0 : board[0].size();

        // represent dead as 1, live as 2;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++ c) {
                board[r][c] += 1;
            }
        }

        std::function<int(int, int)> countLiveNeighbor = [&](int r, int c) {
            int ret = 0;
            for (int i = r - 1; i <= r + 1; ++i) {
                for (int j = c - 1; j <= c + 1; ++j) {
                    if (i < 0 || i >= m || j < 0 || j >= n) { continue; }
                    if (i == r && j == c) { continue; }
                    if (abs(board[i][j]) == 2) {
                        ++ret;
                    }
                }
            }

            return ret;
        };

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++ c) {
                int popcnt = countLiveNeighbor(r, c);
                if (board[r][c] == 2) {
                    board[r][c] = (popcnt < 2 || popcnt > 3) ? -2 : 2;
                }
                else {
                    board[r][c] = (popcnt == 3) ? -1 : 1;
                }
            }
        }

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++ c) {
                switch (board[r][c]) {
                case -1:
                    board[r][c] = 1;
                    break;
                case 1:
                    board[r][c] = 0;
                    break;
                case -2:
                    board[r][c] = 0;
                    break;
                case 2:
                    board[r][c] = 1;
                    break;
                }
            }
        }
    }
};
