class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat.empty() ? 0 : mat[0].size();

        int rowCnts[m], colCnts[n];
        std::fill(rowCnts, rowCnts + m, 0);
        std::fill(colCnts, colCnts + n, 0);
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (mat[r][c] == 1) {
                    ++rowCnts[r], ++colCnts[c];
                }
            }
        }

        int ret = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (mat[r][c] == 1 && rowCnts[r] == 1 && colCnts[c] == 1) {
                    ++ret;
                }
            }
        }

        return ret;
    }
};
