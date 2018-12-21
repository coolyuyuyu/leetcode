class Solution {
public:
    // Space(rowCnt, colCnt) = rowCnt * colCnt
    size_t maximalRectangleV1(const vector<vector<char>>& matrix) {
        size_t rowCnt = matrix.size();
        size_t colCnt = matrix.empty() ? 0 : matrix.front().size();

        size_t maxArea = 0;
        vector<vector<size_t>> lftDp(rowCnt, vector<size_t>(colCnt, 0));
        vector<vector<size_t>> rhtDp(rowCnt, vector<size_t>(colCnt, colCnt));
        vector<vector<size_t>> heightDp(rowCnt, vector<size_t>(colCnt, 0));
        for (size_t col = 0, lftMost = 0; col < colCnt; ++col) {
            if (matrix[0][col] == '1') {
                lftDp[0][col] = lftMost;
            }
            else {
                lftMost = col + 1;
            }
        }
        for (size_t col = colCnt, rhtMost = colCnt; 0 < col--;) {
            if (matrix[0][col] == '1') {
                rhtDp[0][col] = rhtMost;
            }
            else {
                rhtMost = col;
            }
        }
        for (size_t col = 0; col < colCnt; ++col) {
            heightDp[0][col] = matrix[0][col] - '0';
        }
        for (size_t col = 0; col < colCnt; ++col) {
            maxArea = max(maxArea, (rhtDp[0][col] - lftDp[0][col]) * heightDp[0][col]);
        }

        for (size_t row = 1; row < rowCnt; ++row) {
            for (size_t col = 0, lftMost = 0; col < colCnt; ++col) {
                if (matrix[row][col] == '1') {
                    lftDp[row][col] = max(lftDp[row - 1][col], lftMost);
                }
                else {
                    lftDp[row][col] = 0;
                    lftMost = col + 1;
                }
            }
            for (size_t col = colCnt, rhtMost = colCnt; 0 < col--;) {
                if (matrix[row][col] == '1') {
                    rhtDp[row][col] = min(rhtDp[row - 1][col], rhtMost);
                }
                else {
                    rhtDp[row][col] = colCnt;
                    rhtMost = col;
                }
            }
            for (size_t col = 0; col < colCnt; ++col) {
                if (matrix[row][col] == '1') {
                    heightDp[row][col] = heightDp[row - 1][col] + 1;
                }
                else {
                    heightDp[row][col] = 0;
                }
            }
            for (size_t col = 0; col < colCnt; ++col) {
                maxArea = max(maxArea, (rhtDp[row][col] - lftDp[row][col]) * heightDp[row][col]);
            }
        }

        return maxArea;
    }

    size_t maximalRectangleV2(const vector<vector<char>>& matrix) {
        size_t rowCnt = matrix.size();
        size_t colCnt = matrix.empty() ? 0 : matrix.front().size();

        size_t maxArea = 0;
        vector<size_t> lftDp(colCnt, 0);
        vector<size_t> rhtDp(colCnt, colCnt);
        vector<size_t> heightDp(colCnt, 0);
        for (size_t row = 0; row < rowCnt; ++row) {
            for (size_t col = 0, lftMost = 0; col < colCnt; ++col) {
                if (matrix[row][col] == '1') {
                    lftDp[col] = max(lftDp[col], lftMost);
                }
                else {
                    lftDp[col] = 0;
                    lftMost = col + 1;
                }
            }
            for (size_t col = colCnt, rhtMost = colCnt; 0 < col--;) {
                if (matrix[row][col] == '1') {
                    rhtDp[col] = min(rhtDp[col], rhtMost);
                }
                else {
                    rhtDp[col] = colCnt;
                    rhtMost = col;
                }
            }
            for (size_t col = 0; col < colCnt; ++col) {
                if (matrix[row][col] == '1') {
                    heightDp[col] = heightDp[col] + 1;
                }
                else {
                    heightDp[col] = 0;
                }
            }
            for (size_t col = 0; col < colCnt; ++col) {
                maxArea = max(maxArea, (rhtDp[col] - lftDp[col]) * heightDp[col]);
            }
        }

        return maxArea;
    }

    size_t maximalRectangle(vector<vector<char>>& matrix) {
        //return maximalRectangleV1(matrix);

        return maximalRectangleV2(matrix);
    }
};