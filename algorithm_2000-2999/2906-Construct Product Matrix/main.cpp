class Solution {
public:
    int M = 12345;

    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        int lftPdt[m][n], rhtPdt[m][n];
        for (int r = 0; r < m; ++r) {
            grid[r][0] %= M;
            std::partial_sum(
                &(grid[r][0]),
                &(grid[r][n]),
                &(lftPdt[r][0]),
                [&](int x, int y) { return (x  * (y % M)) % M; });

            grid[r][n - 1] %= M;
            std::partial_sum(
                std::make_reverse_iterator(&(grid[r][n])),
                std::make_reverse_iterator(&(grid[r][0])),
                std::make_reverse_iterator(&(rhtPdt[r][n])),
                [&](int x, int y) { return (x  * (y % M)) % M; });
        }

        int rowTopPdt[m], rowBtmPdt[m];
        rowTopPdt[0] = rhtPdt[0][0];
        for (int r = 1; r < m; ++r) {
            rowTopPdt[r] = (rowTopPdt[r - 1] * rhtPdt[r][0]) % M;
        }
        rowBtmPdt[m - 1] = rhtPdt[m - 1][0];
        for (int r = m - 1; 0 < r--;) {
            rowBtmPdt[r] = (rowBtmPdt[r + 1] * rhtPdt[r][0]) % M;
        }

        vector<vector<int>> ret(m, vector<int>(n));
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                int x = 1;
                x = (x * (r > 0 ? rowTopPdt[r - 1] : 1)) % M;
                x = (x * (c > 0 ? lftPdt[r][c - 1] : 1)) % M;
                x = (x * (c + 1 < n ? rhtPdt[r][c + 1] : 1)) % M;
                x = (x * (r + 1 < m ? rowBtmPdt[r + 1] : 1)) % M;
                ret[r][c] = x;
            }
        }

        return ret;
    }
};
