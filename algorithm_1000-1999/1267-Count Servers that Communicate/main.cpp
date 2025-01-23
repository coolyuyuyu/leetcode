class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        vector<int> rowCnts(m, 0), colCnts(n, 0);
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    ++rowCnts[r];
                    ++colCnts[c];
                }
            }
        }

        int ret = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1 && (rowCnts[r] > 1 || colCnts[c] > 1)) {
                    ++ret;
                }
            }
        }

        return ret;
    }
};
