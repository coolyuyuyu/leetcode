class Solution {
public:
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        queue<pair<int, int>> q;
        for (int r = 0; r < n; ++r) {
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
            auto [r, c] = q.front();
            q.pop();

            for (const auto& [dr, dc] : dirs) {
                int x = r + dr, y = c + dc;
                if (x < 0 || n <= x || y < 0 || n <= y) { continue; }
                if (grid[x][y] <= grid[r][c] + 1) { continue; }
                grid[x][y] = grid[r][c] + 1;
                q.emplace(x, y);
            }
        }

        std::function<bool(int)> checkConnected = [&](int safe) {
            if (grid[0][0] < safe || grid[n - 1][n - 1] < safe) { return false; }

            bool visited[n][n];
            for (int r = 0; r < n; ++r) {
                for (int c = 0; c < n; ++c) {
                    visited[r][c] = false;
                }
            }

            queue<pair<int, int>> q;
            visited[0][0] = true;
            q.emplace(0, 0);
            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();

                if (r + 1 == n && c + 1 == n) {
                    return true;
                }

                for (const auto& [dr, dc] : dirs) {
                    int x = r + dr, y = c + dc;
                    if (x < 0 || n <= x || y < 0 || n <= y) { continue; }
                    if (visited[x][y]) { continue; }
                    if (grid[x][y] < safe) { continue; }
                    visited[x][y] = true;
                    q.emplace(x, y);
                }
            }

            return false;
        };

        int lo = 0, hi = 2 * n - 1;
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
