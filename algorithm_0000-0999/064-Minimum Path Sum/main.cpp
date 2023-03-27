class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        size_t m = grid.size(), n = grid.empty() ? 0 : grid[0].size();
        assert(0 < m && 0 < n);

        for (size_t r = 0; r < m; ++r) {
            for (size_t c = 0; c < n; ++c) {
                if (r == 0 && c == 0) {
                    continue;
                }
                grid[r][c] += std::min({0 < r ? grid[r - 1][c] : INT_MAX, 0 < c ? grid[r][c - 1] : INT_MAX});
            }
        }

        return grid[m - 1][n - 1];
    }
};
