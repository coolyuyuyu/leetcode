class Solution {
public:
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        int healths[m][n];
        std::fill(&healths[0][0], &healths[0][0] + m * n, 0);

        priority_queue<tuple<int, int, int>> pq;
        pq.emplace(health, 0, 0);
        while (!pq.empty()) {
            auto [h, r, c] = pq.top();
            pq.pop();

            if (healths[r][c] > 0) { continue; }
            h -= (grid[r][c] == 1);
            if (h == 0) { continue; }
            healths[r][c] = h;

            if (r == m - 1 && c == n - 1) {
                return true;;
            }

            for (const auto& [dr, dc] : dirs) {
                int x = r + dr, y = c + dc;
                if (x < 0 || x >= m || y < 0 || y >= n) { continue; }
                if (healths[x][y] > 0) { continue; }
                pq.emplace(h, x, y);
            }
        }

        return false;
    }
};
