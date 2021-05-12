class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        size_t rowCnt = mat.size(), colCnt = mat.empty() ? 0 : mat.front().size();

        vector<int> rowSpecial(rowCnt, 0), colSpecial(colCnt, 0);
        for (size_t row = 0; row < rowCnt; ++row) {
            for (size_t col = 0; col < colCnt; ++col) {
                if (mat[row][col]) {
                    ++rowSpecial[row];
                    ++colSpecial[col];
                }
            }
        }

        int numSpecial = 0;
        for (size_t row = 0; row < rowCnt; ++row) {
            for (size_t col = 0; col < colCnt; ++col) {
                if (mat[row][col] && rowSpecial[row] == 1 && colSpecial[col] == 1) {
                    ++numSpecial;
                }
            }
        }

        return numSpecial;
    }
};
