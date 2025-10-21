class Solution {
public:
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        bool visited[m][n];
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                visited[r][c] = false;
            }
        }

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, std::greater<>> minPQ;
        minPQ.emplace(grid[0][0], 0, 0);

        int ret = INT_MIN;
        while (!minPQ.empty()) {
            auto [t, r, c] = minPQ.top();
            minPQ.pop();

            if (visited[r][c]) { continue; }
            visited[r][c] = true;

            ret = std::max(ret, t);
            if (r == m - 1 && c == n - 1) {
                break;
            }

            for (const auto& [dr, dc] : dirs) {
                int x = r + dr, y = c + dc;
                if (x < 0 || x >= m || y < 0 || y >= n) { continue; }
                if (visited[x][y]) { continue; }

                minPQ.emplace(grid[x][y], x, y);
            }
        }

        return ret;
    }
};
