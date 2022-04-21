class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        size_t m = grid.size(), n = grid.empty() ? 0 : grid.front().size();

        int area = 0;
        for (size_t r = 0; r < m; ++r) {
            for (size_t c = 0; c < n; ++c) {
                if (grid[r][c]) {
                    area += (4 * (grid[r][c]) + 2);
                }
                if (0 < r) {
                    area -= (2 * std::min(grid[r][c], grid[r - 1][c]));
                }
                if (0 < c) {
                    area -= (2 * std::min(grid[r][c], grid[r][c - 1]));
                }
            }
        }

        return area;
    }
};
