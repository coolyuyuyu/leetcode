class Solution {
public:
    // Time: O(m * n), Space: O(m * n)
    int dp1(const vector<vector<int>>& matrix) {
        size_t m = matrix.size(), n = matrix.empty() ? 0 : matrix[0].size();

        // dp[r][c]: the minimum sum of any falling path down to position (r, c)
        int dp[m][n];
        for (size_t c = 0; c < n; ++c) {
            dp[0][c] = matrix[0][c];
        }
        for (size_t r = 1; r < m; ++r) {
            for (size_t c = 0; c < n; ++c) {
                dp[r][c] = std::min({0 < c ? dp[r - 1][c - 1] : INT_MAX, dp[r - 1][c], c + 1 < n ? dp[r - 1][c + 1] : INT_MAX}) + matrix[r][c];
            }
        }

        return *std::min_element(dp[m - 1], dp[m - 1] + n);
    }

    // Time: O(m * n), Space: O(n)
    int dp2(const vector<vector<int>>& matrix) {
        size_t m = matrix.size(), n = matrix.empty() ? 0 : matrix[0].size();

        // dp[r][c]: the minimum sum of any falling path down to position (r, c)
        int dp[n];
        for (size_t c = 0; c < n; ++c) {
            dp[c] = matrix[0][c];
        }
        for (size_t r = 1; r < m; ++r) {
            int tmp[n];
            std::copy(dp, dp + n, tmp);
            for (size_t c = 0; c < n; ++c) {
                dp[c] = std::min({0 < c ? tmp[c - 1] : INT_MAX, tmp[c], c + 1 < n ? tmp[c + 1] : INT_MAX}) + matrix[r][c];
            }
        }

        return *std::min_element(dp, dp + n);
    }

    // Time: O(m * n), Space: O(1)
    int dp3(vector<vector<int>>& matrix) {
        size_t m = matrix.size(), n = matrix.empty() ? 0 : matrix[0].size();

        for (size_t r = 1; r < m; ++r) {
            for (size_t c = 0; c < n; ++c) {
                matrix[r][c] += std::min({0 < c ? matrix[r - 1][c - 1] : INT_MAX, matrix[r - 1][c], c + 1 < n ? matrix[r - 1][c + 1] : INT_MAX});
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
