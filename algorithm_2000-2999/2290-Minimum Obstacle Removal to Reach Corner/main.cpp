class Solution {
public:
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        bool visited[m][n];
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                visited[r][c] = false;
            }
        }
        queue<pair<int, int>> q1;

        std::function<bool(int, int)> f = [&](int r, int c){
            queue<pair<int, int>> q2;
            q2.emplace(r, c);
            visited[r][c] = true;
            while (!q2.empty()) {
                auto [r, c] = q2.front();
                q2.pop();

                if (r == m - 1 && c == n - 1) {
                    return true;
                }

                for (const auto& [dr, dc] : dirs) {
                    int x = r + dr, y = c + dc;
                    if (x < 0 || x >= m || y < 0 || y >= n) { continue; }
                    if (visited[x][y]) { continue; }
                    visited[x][y] = true;

                    if (grid[x][y] == 1) {
                        q1.emplace(x, y);
                    }
                    else {
                        q2.emplace(x, y);
                    }
                }
            }

            return false;
        };

        q1.emplace(0, 0);
        visited[0][0] = true;
        for (int step = 0; !q1.empty(); ++step) {
            for (int i = q1.size(); 0 < i--;) {
                auto [r, c] = q1.front();
                q1.pop();

                if (f(r, c)) {
                    return step;
                }
            }
        }

        __builtin_unreachable();
        return -1;
    }
};
