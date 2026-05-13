class Solution {
public:
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> grid(n, vector<int>(m, 0));
        queue<tuple<int, int, int>> q; // <r, c, color>

        for (const auto& source : sources) {
            int r = source[0], c = source[1], color = source[2];
            grid[r][c] = color;
            q.emplace(r, c, color);
        }

        while (!q.empty()) {
            map<pair<int, int>, int> pos2color;
            for (int i = q.size(); 0 < i--;) {
                auto [r, c, color] = q.front();
                q.pop();

                for (const auto& [dr, dc] : dirs) {
                    int x = r + dr, y = c + dc;
                    if (x < 0 || x >= n || y < 0 || y >= m) { continue; }
                    if (grid[x][y] > 0) { continue; }
                    pos2color[{x, y}] = std::max(pos2color[{x, y}], color);
                }
            }

            for (const auto& [pos, color] : pos2color) {
                const auto& [r, c] = pos;
                grid[r][c] = color;
                q.emplace(r, c, color);
            }
        }

        return grid;
    }
};
