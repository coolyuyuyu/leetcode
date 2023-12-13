class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat.empty() ? 0 : mat[0].size();

        int rowCnt[m], colCnt[n];
        std::fill(rowCnt, rowCnt + m, 0);
        std::fill(colCnt, colCnt + n, 0);
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (mat[r][c] == 1) {
                    ++rowCnt[r];
                    ++colCnt[c];
                }
            }
        }

        int ret = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (mat[r][c] == 1 && rowCnt[r] == 1 && colCnt[c] == 1) {
                    ++ret;
                }
            }
        }

        return ret;
    }
};
