class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        int m = heights.size(), n = heights.empty() ? 0 : heights[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n, false)), atl(m, vector<bool>(n, false));
        std::function<void(vector<vector<bool>>&, int, int)> bfs = [&](vector<vector<bool>>& sea, int r, int c) {
            if (sea[r][c]) { return; }

            queue<pair<int, int>> q;
            sea[r][c] = true;
            q.emplace(r, c);
            while (!q.empty()) {
                const auto [r, c] = q.front();
                q.pop();

                for (const auto& [dr, dc] : dirs) {
                    int x = r + dr, y = c + dc;
                    if (x < 0 || m <= x || y < 0 || n <= y) { continue; }
                    if (sea[x][y]) { continue; }
                    if (heights[x][y] < heights[r][c]) { continue; }

                    sea[x][y] = true;
                    q.emplace(x, y);
                }
            }
        };
        for (int r = 0; r < m; ++r) {
            bfs(pac, r, 0);
            bfs(atl, r, n - 1);
        }
        for (int c = 0; c < n; ++c) {
            bfs(pac, 0, c);
            bfs(atl, m - 1, c);
        }

        vector<vector<int>> ret;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (pac[r][c] && atl[r][c]) {
                    ret.push_back({r, c});
                }
            }
        }

        return ret;
    }
};
