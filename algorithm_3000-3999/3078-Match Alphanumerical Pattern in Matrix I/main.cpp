class Solution {
public:
    vector<int> findPattern(vector<vector<int>>& board, vector<string>& pattern) {
        int m = board.size(), n = board.empty() ? 0 : board[0].size();
        int a = pattern.size(), b = pattern.empty() ? 0 : pattern[0].size();

        std::function<bool(int, int)> check = [&](int r, int c) {
            unordered_map<char, int> m;
            vector<bool> used(10, false);
            for (int i = 0; i < a; ++i) {
                for (int j = 0; j < b; ++j) {
                    char ch = pattern[i][j];
                    if (isdigit(ch)) {
                        if (ch - '0' != board[r + i][c + j]) {
                            return false;
                        }
                    }
                    else if (m.find(ch) == m.end()) {
                        if (used[board[r + i][c + j]]) {
                            return false;
                        }
                        m[ch] = board[r + i][c + j];
                        used[board[r + i][c + j]] = true;
                    }
                    else {
                        if (m[ch] != board[r + i][c + j]) {
                            return false;
                        }
                    }
                }
            }

            return true;
        };

        for (int r = 0; r + a <= m; ++r) {
            for (int c = 0; c + b <= n; ++c) {
                if (check(r, c)) {
                    return {r, c};
                }
            }
        }

        return {-1, -1};
    }
};
