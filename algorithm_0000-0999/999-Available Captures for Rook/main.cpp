class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        auto getRook = [&]() -> pair<int, int>{
            for (int r = 0; r < 8; ++r) {
                for (int c = 0; c < 8; ++c) {
                    if (board[r][c] == 'R') {
                        return {r, c};
                    }
                }
            }

            assert(false);
            return {-1, -1};
        };
        auto [rx, ry] = getRook();

        int cnt = 0;
        // lft
        for (int x = rx, y = ry - 1; 0 <= y; --y) {
            if (board[x][y] == 'B') {
                break;
            }
            else if (board[x][y] == 'p') {
                ++cnt;
                break;
            }
        }

        // top
        for (int x = rx - 1, y = ry; 0 <= x; --x) {
            if (board[x][y] == 'B') {
                break;
            }
            else if (board[x][y] == 'p') {
                ++cnt;
                break;
            }
        }

        // rht
        for (int x = rx, y = ry + 1; y < 8; ++y) {
            if (board[x][y] == 'B') {
                break;
            }
            else if (board[x][y] == 'p') {
                ++cnt;
                break;
            }
        }

        // btm
        for (int x = rx + 1, y = ry; x < 8; ++x) {
            if (board[x][y] == 'B') {
                break;
            }
            else if (board[x][y] == 'p') {
                ++cnt;
                break;
            }
        }

        return cnt;
    }
};
