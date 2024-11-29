class Solution {
public:
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }

        int times[m][n];
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                times[r][c] = -1;
            }
        }
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, std::greater<tuple<int, int, int>>> pq; // <t, r, c>
        pq.emplace(0, 0, 0);
        while (!pq.empty()) {
            auto [t, r, c] = pq.top();
            pq.pop();

            if (times[r][c] >= 0) { continue; }
            times[r][c] = t;

            if (r == m - 1 && c == n - 1) {
                break;
            }

            for (const auto& [dr, dc] : dirs) {
                int x = r + dr, y = c + dc;
                if (x < 0 || x >= m || y < 0 || y >= n) { continue; }
                if (times[x][y] >= 0) { continue; }

                if (t + 1 >= grid[x][y]) {
                    pq.emplace(t + 1, x, y);
                }
                else {
                    pq.emplace(grid[x][y] + (((grid[x][y] - t) & 1) ? 0 : 1), x, y);
                }
            }
        }

        return times[m - 1][n - 1];
    }
};
