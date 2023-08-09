class Solution {
public:
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        queue<pair<int, int>> q;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    q.emplace(r, c);
                }
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (const auto& [dr, dc] : dirs) {
                int x = r + dr, y = c + dc;
                if (x < 0 || n <= x || y < 0 || n <= y) { continue; }
                if (grid[x][y] > 0) { continue; }
                grid[x][y] = grid[r][c] + 1;

                q.emplace(x, y);
            }
        }

        std::function<bool(int)> isOk = [&](int safeFactor) {
            if (grid[0][0] <= safeFactor) {
                return false;
            }

            vector<vector<bool>> visited(n, vector<bool>(n, false));
            visited[0][0] = true;
            queue<pair<int, int>> q({{0, 0}});
            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();

                for (const auto& [dr, dc] : dirs) {
                    int x = r + dr, y = c + dc;
                    if (x < 0 || n <= x || y < 0 || n <= y) { continue; }
                    if (visited[x][y]) { continue; }
                    if (grid[x][y] <= safeFactor) { continue; }

                    if (x + 1 == n && y + 1 == n) {
                        return true;
                    }

                    visited[x][y] = true;
                    q.emplace(x, y);
                }

            }

            return false;
        };

        int lo = 0, hi = 2 * n - 1;
        while (lo < hi) {
            int mid = hi - (hi - lo) / 2;
            if (isOk(mid)) {
                lo = mid;
            }
            else {
                hi = mid - 1;
            }
        }

        return lo;
    }
};
