class Solution {
public:
    vector<pair<int, int>> dirs = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

    vector<vector<int>> tourOfKnight(int m, int n, int r, int c) {
        vector<vector<int>> grid(m, vector<int>(n, -1));
        std::function<bool(int, int, int)> dfs = [&](int i, int r, int c) {
            if (grid[r][c] >= 0) {
                return false;
            }

            grid[r][c] = i;
            if (i >= (m * n - 1)) {
                return true;
            }
            for (const auto& [dr, dc] : dirs) {
                int x = r + dr, y = c + dc;
                if (x < 0 || x >= m || y < 0 || y >= n) { continue; }

                if (dfs(i + 1, x , y)) {
                    return true;
                }
            }
            grid[r][c] = -1;

            return false;

        };
        dfs(0, r, c);

        return grid;
    }
};
