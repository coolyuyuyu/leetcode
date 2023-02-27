class Solution {
public:
    vector<array<int, 2>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    int minimumTime(vector<vector<int>>& grid) {
        if (1 < grid[0][1] && 1 < grid[1][0]) {
            return -1;
        }

        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> times(m, vector<int>(n, -1));

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(grid[0][0], 0, 0);
        while (!pq.empty()) {
            auto [t, r, c] = pq.top();
            pq.pop();

            if (0 <= times[r][c]) { // visited
                continue;
            }
            times[r][c] = t;

            if (r == (m - 1) && c == (n - 1)) {
                break;
            }

            for (const auto& dir : dirs) {
                int i = r + dir[0], j = c + dir[1];
                if (i < 0 || m <= i || j < 0 || n <= j) {
                    continue;
                }
                if (0 <= times[i][j]) {
                    continue;
                }

                if (grid[i][j] <= t + 1) {
                    pq.emplace(t + 1, i, j);
                }
                else if ((grid[i][j] - t) % 2) {
                    pq.emplace(grid[i][j], i, j);
                }
                else {
                    pq.emplace(grid[i][j] + 1, i, j);
                }
            }
        }

        return times[m - 1][n - 1];
    }
};
