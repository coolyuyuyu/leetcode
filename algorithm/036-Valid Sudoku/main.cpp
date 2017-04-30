class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> counts(9, 1);

        for (int i = 0; i < 9; ++i) {
            vector<int> cnts = counts;
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c == '.') {
                    continue;
                }

                --cnts[c - '1'];
                if (cnts[c - '1'] < 0) {
                    return false;
                }
            }
        }

        for (int i = 0; i < 9; ++i) {
            vector<int> cnts = counts;
            for (int j = 0; j < 9; ++j) {
                char c = board[j][i];
                if (c == '.') {
                    continue;
                }

                --cnts[c - '1'];
                if (cnts[c - '1'] < 0) {
                    return false;
                }
            }
        }

        for (int i = 0; i < 9; ++i) {
            vector<int> cnts = counts;
            int a = i / 3 * 3;
            int b = i % 3 * 3;
            for (int j = 0; j < 9; ++j) {
                char c = board[a + j / 3][b + j % 3];
                if (c == '.') {
                    continue;
                }

                --cnts[c - '1'];
                if (cnts[c - '1'] < 0) {
                    return false;
                }
            }
        }

        return true;
    }
};