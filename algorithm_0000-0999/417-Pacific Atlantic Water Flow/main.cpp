class Solution {
public:
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights.empty() ? 0 : heights[0].size();

        std::function<void(int, int, vector<vector<bool>>&)> bfs = [&](int r, int c, vector<vector<bool>>& sea) {
            if (sea[r][c]) { return; }

            queue<pair<int, int>> q({{r, c}});
            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();

                if (sea[r][c]) { continue; }
                sea[r][c] = true;

                for (const auto& [dr, dc] : dirs) {
                    int x = r + dr, y = c + dc;
                    if (x < 0 || x >= m || y < 0 || y >= n) { continue; }
                    if (heights[x][y] < heights[r][c]) { continue; }
                    if (sea[x][y]) { continue; }

                    q.emplace(x, y);
                }
            }

        };

        vector<vector<bool>> pac(m, vector<bool>(n, false)), atl(m, vector<bool>(n, false));
        for (int r = 0; r < m; ++r) {
            bfs(r, 0, pac);
            bfs(r, n - 1, atl);
        }
        for (int c = 0; c < n; ++c) {
            bfs(0, c, pac);
            bfs(m - 1, c, atl);
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
