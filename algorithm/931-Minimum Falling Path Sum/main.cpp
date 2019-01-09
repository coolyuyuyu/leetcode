class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        size_t rowCnt = A.size(), colCnt = A.empty() ? 0 : A.front().size();

        vector<vector<int>> dp(rowCnt, vector<int>(colCnt, 0));
        dp[0] = A[0];
        for (size_t row = 1; row < rowCnt; ++row) {
            for (size_t col = 0; col < colCnt; ++col) {
                dp[row][col] = dp[row - 1][col];
                if (0 < col) {
                    dp[row][col] = min(dp[row][col], dp[row - 1][col - 1]);
                }
                if (col + 1 < colCnt) {
                    dp[row][col] = min(dp[row][col], dp[row - 1][col + 1]);
                }
                dp[row][col] += A[row][col];
            }
        }

        return *min_element(dp.back().begin(), dp.back().end());
    }
};