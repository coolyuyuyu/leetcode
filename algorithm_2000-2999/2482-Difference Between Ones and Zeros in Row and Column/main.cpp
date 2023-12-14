class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        int rowOneCnt[m], colOneCnt[n];
        std::fill(rowOneCnt, rowOneCnt + m, 0);
        std::fill(colOneCnt, colOneCnt + n, 0);
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    ++rowOneCnt[r];
                    ++colOneCnt[c];
                }
            }
        }

        vector<vector<int>> ret(m, vector<int>(n));
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                ret[r][c] = (rowOneCnt[r] + colOneCnt[c]) * 2 - m - n;
            }
        }

        return ret;
    }
};
