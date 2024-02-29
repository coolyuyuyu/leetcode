class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board.empty() ? 0 : board[0].size();

        int ret = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (board[r][c] == '.') { continue; }
                if (r - 1 >= 0 && board[r - 1][c] == 'X') { continue; }
                if (c - 1 >= 0 && board[r][c - 1] == 'X') { continue; }

                ++ret;
            }
        }

        return ret;
    }
};
