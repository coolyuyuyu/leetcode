class Solution {
public:
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        queue<pair<int, int>> q;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    grid[r][c] = 0;
                    q.emplace(r, c);
                }
                else {
                    grid[r][c] = INT_MAX;
                }
            }
        }

        while (!q.empty()) {
            for (int i = q.size(); 0 < i--;) {
                auto [r, c] = q.front();
                q.pop();

                for (const auto& [dr, dc] : dirs) {
                    int x = r + dr, y = c + dc;
                    if (x < 0 || x >= m || y < 0 || y >= n) { continue; }
                    if (grid[x][y] < INT_MAX) { continue; }
                    grid[x][y] = grid[r][c] + 1;
                    q.emplace(x, y);
                }
            }
        }

        std::function<bool(int)> checkConnected = [&](int safe) {
            if (grid[0][0] < safe || grid[n - 1][n - 1] < safe) { return false; }

            bool visited[m][n];
            std::fill(&visited[0][0], &visited[0][0] + m * n, false);
            for (queue<pair<int, int>> q({{0, 0}}); !q.empty();) {
                auto [r, c] = q.front();
                q.pop();

                if (r + 1 == m && c + 1 == n) {
                    return true;
                }

                for (const auto& [dr, dc] : dirs) {
                    int x = r + dr, y = c + dc;
                    if (x < 0 || x >= m || y < 0 || y >= n) { continue; }
                    if (grid[x][y] < safe) { continue; }
                    if (visited[x][y]) { continue; }
                    visited[x][y] = true;
                    q.emplace(x, y);
                }
            }
            return false;
        };

        int lo = 0, hi = m + n - 1;
        while (lo < hi) {
            int mid = hi - (hi - lo) / 2;
            if (checkConnected(mid)) {
                lo = mid;
            }
            else {
                hi = mid - 1;
            }
        }

        return lo;
    }
};
