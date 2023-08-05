class Solution {
public:
    // Space: O(m * n)
    int dp1(const vector<vector<int>>& matrix) {
        size_t m = matrix.size(), n = matrix.empty() ? 0 : matrix[0].size();

        //dp[i][j]: the minimum sum of  any falling path down to (i, j);
        vector<vector<int>> dp(m, vector<int>(n));
        for (size_t c = 0; c < n; ++c) {
            dp[0][c] = matrix[0][c];
        }
        for (size_t r = 1; r < m; ++r) {
            for (size_t c = 0; c < n; ++c) {
                dp[r][c] = matrix[r][c] + std::min({0 < c ? dp[r - 1][c - 1] : INT_MAX, dp[r - 1][c], (c + 1) < n ? dp[r - 1][c + 1] : INT_MAX});
            }
        }

        return *std::min_element(dp[m - 1].begin(), dp[m - 1].end());
    }

    // Space: O(n)
    int dp2(const vector<vector<int>>& matrix) {
        size_t m = matrix.size(), n = matrix.empty() ? 0 : matrix[0].size();

        //dp[i][j]: the minimum sum of  any falling path down to (i, j);
        vector<int> dp(n);
        for (size_t c = 0; c < n; ++c) {
            dp[c] = matrix[0][c];
        }
        for (size_t r = 1; r < m; ++r) {
            vector<int> tmp = dp;
            for (size_t c = 0; c < n; ++c) {
                dp[c] = matrix[r][c] + std::min({0 < c ? tmp[c - 1] : INT_MAX, tmp[c], (c + 1) < n ? tmp[c + 1] : INT_MAX});
            }
        }

        return *std::min_element(dp.begin(), dp.end());
    }

    // Space: O(1)
    int dp3(vector<vector<int>>& matrix) {
        size_t m = matrix.size(), n = matrix.empty() ? 0 : matrix[0].size();

        for (size_t r = 1; r < m; ++r) {
            for (size_t c = 0; c < n; ++c) {
                matrix[r][c] += std::min({0 < c ? matrix[r - 1][c - 1] : INT_MAX, matrix[r - 1][c], (c + 1) < n ? matrix[r - 1][c + 1] : INT_MAX});
            }
        }

        return *std::min_element(matrix[m - 1].begin(), matrix[m - 1].end());
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        //return dp1(matrix);
        //return dp2(matrix);
        return dp3(matrix);
    }
};
