class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        for (int c = 0; c < n; ++c) {
            for (int r = 1; r < m; ++r) {
                if (grid[r][c] != grid[0][c]) {
                    return false;
                }
            }
        }

        for (int c = 1; c < n; ++c) {
            if (grid[0][c - 1] == grid[0][c]) {
                return false;
            }
        }

        return true;
    }
};
