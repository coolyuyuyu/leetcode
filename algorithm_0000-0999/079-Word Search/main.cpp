class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board.empty() ? 0 : board[0].size();
        std::function<bool(int, int, int)> dfs = [&](int r, int c, int i) {
            if (board[r][c] != word[i]) {
                return false;
            }
            if (i + 1 >= word.size()) {
                return true;
            }

            char ch = board[r][c];
            board[r][c] = 0;
            bool found = 
                (c > 0 && dfs(r, c - 1, i + 1)) ||
                (r > 0 && dfs(r - 1, c, i + 1)) ||
                (c + 1 < n && dfs(r, c + 1, i + 1)) ||
                (r + 1 < m && dfs(r + 1, c, i + 1));
            board[r][c] = ch;
            return found;
        };

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (dfs(r, c, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};
