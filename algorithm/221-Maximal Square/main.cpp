class Solution {
public:
    // Space(rowCnt, colCnt) = rowCnt * colCnt
    size_t maximalSquareV1(vector<vector<char>>& matrix) {
        size_t rowCnt = matrix.size();
        size_t colCnt = matrix.empty() ? 0 : matrix.front().size();

        size_t maxLength = 0;
        vector<vector<size_t>> dp(rowCnt, vector<size_t>(colCnt, 0));
        for (size_t row = 0; row < rowCnt; ++row) {
            dp[row][0] = matrix[row][0] - '0';
            maxLength = max(maxLength, dp[row][0]);
        }
        for (size_t col = 0; col < colCnt; ++col) {
            dp[0][col] = matrix[0][col] - '0';
            maxLength = max(maxLength, dp[0][col]);
        }

        for (size_t row = 1; row < rowCnt; ++row) {
            for (size_t col = 1; col < colCnt; ++col) {
                if (matrix[row][col] == '1') {
                    dp[row][col] = min(dp[row - 1][col - 1], min(dp[row - 1][col], dp[row][col - 1])) + 1;
                    maxLength = max(maxLength, dp[row][col]);
                }
                else {
                    dp[row][col] = 0;
                }
            }
        }

        return maxLength * maxLength;
    }

    // Space(rowCnt, colCnt) = colCnt
    size_t maximalSquareV2(vector<vector<char>>& matrix) {
        size_t rowCnt = matrix.size();
        size_t colCnt = matrix.empty() ? 0 : matrix.front().size();

        size_t maxLength = 0;
        vector<size_t> dp(colCnt, 0);
        for (size_t col = 0; col < colCnt; ++col) {
            dp[col] = matrix[0][col] - '0';
            maxLength = max(maxLength, dp[col]);
        }
        for (size_t row = 0; row < rowCnt && maxLength == 0; ++row) {
            if (matrix[row][0] == '1') {
                maxLength = 1;
            }
        }

        for (size_t row = 1; row < rowCnt; ++row) {
            size_t prevLength = dp[0];
            dp[0] = matrix[row][0] - '0';
            for (size_t col = 1; col < colCnt; ++col) {
                size_t tmp = dp[col];
                if (matrix[row][col] == '1') {
                    dp[col] = min(prevLength, min(dp[col], dp[col - 1])) + 1;
                    maxLength = max(maxLength, dp[col]);
                }
                else {
                    dp[col] = 0;
                }

                prevLength = tmp;
            }
        }

        return maxLength * maxLength;
    }

    size_t maximalSquare(vector<vector<char>>& matrix) {
        //return maximalSquareV1(matrix);

        return maximalSquareV2(matrix);
    }
};