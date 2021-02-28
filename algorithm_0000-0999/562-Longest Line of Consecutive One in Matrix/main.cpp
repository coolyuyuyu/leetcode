class Solution {
public:
    size_t longestLine(vector<vector<int>>& M) {
        size_t rowCnt = M.size();
        size_t colCnt = M.empty() ? 0 : M.front().size();

        size_t maxHorizontal = 0;
        for (size_t row = 0; row < rowCnt; ++row) {
            size_t horizontal = 0;
            for (size_t col = 0; col < colCnt; ++col) {
                if (M[row][col]) {
                    ++horizontal;
                    maxHorizontal = max(maxHorizontal, horizontal);
                }
                else {
                    horizontal = 0;
                }
            }
        }

        size_t maxVertical = 0;
        for (size_t col = 0; col < colCnt; ++col) {
            size_t vertical = 0;
            for (size_t row = 0; row < rowCnt; ++row) {
                if (M[row][col]) {
                    ++vertical;
                    maxVertical = max(maxVertical, vertical);
                }
                else {
                    vertical = 0;
                }
            }
        }

        size_t maxUprLftLwrRht = 0;
        size_t maxUprRhtLwrLft = 0;
        vector<size_t> dpUprLftLwrRht(colCnt);
        vector<size_t> dpUprRhtLwrLft(colCnt);
        for (size_t col = 0; col < colCnt; ++col) {
            dpUprLftLwrRht[col] = dpUprRhtLwrLft[col] = M[0][col];
        }
        for (size_t row = 1; row < rowCnt; ++row) {
            for (size_t col = colCnt; 1 < col--;) {
                if (M[row][col]) {
                    dpUprLftLwrRht[col] = dpUprLftLwrRht[col - 1] + 1;
                    maxUprLftLwrRht = max(maxUprLftLwrRht, dpUprLftLwrRht[col]);
                }
                else {
                    dpUprLftLwrRht[col] = 0;
                }
            }

            for (size_t col = 0; col + 1 < colCnt; ++col) {
                if (M[row][col]) {
                    dpUprRhtLwrLft[col] = dpUprRhtLwrLft[col + 1] + 1;
                    maxUprRhtLwrLft = max(maxUprRhtLwrLft, dpUprRhtLwrLft[col]);
                }
                else {
                    dpUprRhtLwrLft[col] = 0;
                }
            }
        }

        return max(max(maxHorizontal, maxVertical), max(maxUprLftLwrRht, maxUprRhtLwrLft));
    }
};