class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix.empty() ? 0 : matrix[0].size();

        // dp[r][c]: the length of maximal squre where bottom-right cornert at (r, c);
        int dp[m][n];
        int ret = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (matrix[r][c] == 0) {
                    dp[r][c] = 0;
                    continue;
                }

                if (r == 0 || c == 0) {
                    dp[r][c] = 1;
                }
                else {
                    dp[r][c] = std::min({dp[r - 1][c], dp[r][c - 1], dp[r - 1][c - 1]}) + 1;
                }
                ret += dp[r][c];
            }
        }

        return ret;
    }
};
