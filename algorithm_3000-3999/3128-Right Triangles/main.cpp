class Solution {
public:
    int cntLft[1005][1005];
    int cntTop[1005][1005];
    int cntRht[1005][1005];
    int cntBtm[1005][1005];
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                cntLft[r][c] = (c > 0 ? cntLft[r][c - 1] : 0) + grid[r][c];
                cntTop[r][c] = (r > 0 ? cntTop[r - 1][c] : 0) + grid[r][c];
            }
        }
        for (int r = m; 0 < r--;) {
            for (int c = n; 0 < c--;) {
                cntRht[r][c] = (c + 1 < n ? cntRht[r][c + 1] : 0) + grid[r][c];
                cntBtm[r][c] = (r + 1 < m ? cntBtm[r + 1][c] : 0) + grid[r][c];
            }
        }

        long long ret = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 0) { continue; }
                ret += (cntLft[r][c] - 1) * (cntTop[r][c] - 1);
                ret += (cntLft[r][c] - 1) * (cntBtm[r][c] - 1);
                ret += (cntRht[r][c] - 1) * (cntTop[r][c] - 1);
                ret += (cntRht[r][c] - 1) * (cntBtm[r][c] - 1);
            }
        }

        return ret;
    }
};
