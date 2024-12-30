class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        int ret = 0;
        for (int c = 0; c < n; ++c) {
            for (int r = 1; r < m; ++r) {
                int val = std::max(grid[r - 1][c] + 1, grid[r][c]);
                ret += val - grid[r][c];
                grid[r][c] = val;
            }
        }

        return ret;
    }
};
