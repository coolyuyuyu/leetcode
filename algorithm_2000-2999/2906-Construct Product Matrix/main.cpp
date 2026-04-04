class Solution {
public:
    int M = 12345;

    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        int rowPdts[m];
        for (int r = 0; r < m; ++r) {
            rowPdts[r] = std::accumulate(&grid[r][0], &grid[r][n], 1, [&](int x, int y){
                return x * (y % M) % M; });
        }
        int topPdts[m], btmPdts[m];
        for (int r = 0; r < m; ++r) {
            topPdts[r] = (r > 0 ? topPdts[r - 1] : 1) * rowPdts[r] % M;
            btmPdts[m - r - 1] = (r > 0 ? btmPdts[m - r] : 1) * rowPdts[m - r - 1] % M;
        }

        vector<vector<int>> ret(m, vector<int>(n));
        for (int r = 0; r < m; ++r) {
            int x = 1;
            x = x * (r > 0 ? topPdts[r - 1] : 1) % M;
            x = x * (r + 1 < m ? btmPdts[r + 1] : 1) % M;

            int prePdts[n], sufPdts[n];
            for (int c = 0; c < n; ++c) {
                prePdts[c] = (c > 0 ? prePdts[c - 1] : 1) * (grid[r][c] % M) % M;
                sufPdts[n - c - 1] = (c > 0 ? sufPdts[n - c] : 1) * (grid[r][n - c - 1] % M) % M;
            }
            for (int c = 0; c < n; ++c) {
                int y = x;
                y = y * (c > 0 ? prePdts[c - 1] : 1) % M;
                y = y * (c + 1 < n ? sufPdts[c + 1] : 1) % M;
                ret[r][c] = y;
            }
        }

        return ret;
    }
};
