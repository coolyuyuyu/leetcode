class Solution {
public:
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        int healths[m][n];
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                healths[r][c] = 0;
            }
        }

        priority_queue<tuple<int, int, int>> pq; // <health, x, y>
        pq.emplace(health, 0, 0);
        while (!pq.empty()) {
            auto [hp, r, c] = pq.top();
            pq.pop();

            hp -= (grid[r][c] == 1 ? 1 : 0);
            if (hp <= 0) { continue; }
            if (healths[r][c] > 0) { continue; }
            healths[r][c] = hp;
            if (r == m - 1 && c == n - 1) { break; }

            for (const auto& [dr, dc] : dirs) {
                int x = r + dr, y = c + dc;
                if (x < 0 || x >= m || y < 0 || y >= n) { continue; }
                if (healths[x][y] > 0) { continue; }

                pq.emplace(hp, x, y);
            }
        }

        return healths[m - 1][n - 1] > 0;
    }
};
