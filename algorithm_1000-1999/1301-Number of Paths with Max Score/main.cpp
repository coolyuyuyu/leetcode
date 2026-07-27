class Solution {
public:
    int M = 1e9 + 7;
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {1, 1}};

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int m = board.size(), n = board.empty() ? 0 : board[0].size();

        int dp1[m][n]; // dp1[r][c]: the maximum sum which can be collected from (m-1,n-1) to (r,c)
        int dp2[m][n]; // dp2[r][c]: the number of paths to acquire dp1[r][c] from (m-1,n-1) to (r,c)

        dp1[m - 1][n - 1] = 0;
        dp2[m - 1][n - 1] = 1;
        for (int r = m - 1; r >= 0; r--) {
            for (int c = n - 1; c >= 0; c--) {
                if (r == m - 1 && c == n - 1) { continue; }
                dp1[r][c] = dp2[r][c] = 0;
                if (board[r][c] == 'X') { continue; }

                for (const auto& [dr, dc] : dirs) {
                    int x = r + dr, y = c + dc;
                    if (x < 0 || x >= m || y < 0 || y >= n) { continue; }
                    if (dp2[x][y] == 0) { continue; }
                    if (dp1[r][c] < dp1[x][y]) {
                        dp1[r][c] = dp1[x][y];
                        dp2[r][c] = dp2[x][y];
                    }
                    else if (dp1[r][c] == dp1[x][y]) {
                        dp2[r][c] += dp2[x][y];
                        dp2[r][c] %= M;
                    }
                }
                if (r != 0 || c != 0) {
                    dp1[r][c] += (board[r][c] - '0');
                }
            }
        }

        return {dp1[0][0], dp2[0][0]};
    }
};
