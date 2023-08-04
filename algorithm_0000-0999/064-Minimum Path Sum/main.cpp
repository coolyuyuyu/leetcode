class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        size_t m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        for (size_t r = 1; r < m; ++r) {
            grid[r][0] += grid[r - 1][0];
        }
        for (size_t c = 1; c < n; ++c) {
            grid[0][c] += grid[0][c - 1];
        }
        for (size_t r = 1; r < m; ++r) {
            for (size_t c = 1; c < n; ++c) {
                grid[r][c] += std::min(0 < r ? grid[r - 1][c] : INT_MAX, 0 < c ? grid[r][c - 1] : INT_MAX);
            }
        }

        return grid[m - 1][n - 1];
    }
};
