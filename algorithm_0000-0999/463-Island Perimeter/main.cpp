class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        int ret = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 0) { continue; }

                ret += 4;
                if (r > 0 && grid[r - 1][c] == 1) {
                    ret -= 2;
                }
                if (c > 0 && grid[r][c - 1] == 1) {
                    ret -= 2;
                }
            }
        }

        return ret;
    }
};
