class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix.empty() ? 0 : matrix[0].size();

        // dp[r][c]: the length of maximal square whose bottom-right corner at (r,c)
        int dp[m][n];
        int ret = 0;
        ret += (dp[0][0] = matrix[0][0]);
        for (int c = 1; c < n; ++c) {
            ret += (dp[0][c] = matrix[0][c]);
        }
        for (int r = 1; r < m; ++r) {
            ret += (dp[r][0] = matrix[r][0]);
        }
        for (int r = 1; r < m; ++r) {
            for (int c = 1; c < n; ++c) {
                if (matrix[r][c] == 0) {
                    dp[r][c] = 0;
                }
                else {
                    dp[r][c] = std::min({dp[r - 1][c], dp[r][c - 1], dp[r - 1][c - 1]}) + 1;
                    ret += dp[r][c];
                }
            }
        }

        return ret;
    }
};
