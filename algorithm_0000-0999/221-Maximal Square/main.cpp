class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix.empty() ? 0 : matrix[0].size();

        // dp[i][j]: the length of largest square containing only 1's and its bottom-right corner is (i, j)
        vector<vector<int>> dp(m, vector<int>(n));
        int len = 0;
        for (int r = 0; r < m; ++r) {
            dp[r][0] = matrix[r][0] - '0';
            len = std::max(len, dp[r][0]);
        }
        for (int c = 0; c < n; ++c) {
            dp[0][c] = matrix[0][c] - '0';
            len = std::max(len, dp[0][c]);
        }
        for (int r = 1; r < m; ++r) {
            for (int c = 1; c < n; ++c) {
                if (matrix[r][c] == '1') {
                    dp[r][c] = std::min({dp[r - 1][c], dp[r][c - 1], dp[r - 1][c - 1]}) + 1;
                    len = std::max(len, dp[r][c]);
                }
                else {
                    dp[r][c] = 0;
                }
            }
        }

        return len * len;
    }
};
