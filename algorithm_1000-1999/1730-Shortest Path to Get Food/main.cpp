class Solution {
public:
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    int getFood(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        pair<int, int> src;
        bool visited[m][n];
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == '*') {
                    src = {r, c};
                }
                visited[r][c] = false;
            }
        }

        queue<pair<int, int>> q;
        visited[src.first][src.second] = true;
        q.push(src);
        for (int step = 0; !q.empty(); ++step) {
            for (int i = q.size(); 0 < i--;) {
                auto [r, c] = q.front();
                q.pop();

                if (grid[r][c] == '#') {
                    return step;
                }

                for (const auto& [dr, dc] : dirs) {
                    int x = r + dr, y = c + dc;
                    if (x < 0 || x >= m || y < 0 || y >= n) { continue; }
                    if (visited[x][y]) { continue; }
                    if (grid[x][y] == 'X') { continue; }

                    visited[x][y] = true;
                    q.emplace(x, y);
                }
            }
        }

        return -1;
    }
};
