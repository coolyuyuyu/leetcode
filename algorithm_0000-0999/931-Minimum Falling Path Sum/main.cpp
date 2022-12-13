class Solution {
public:
    // Time: O(mn), Space: O(mn)
    int dp1(vector<vector<int>>& matrix) {
        assert(!matrix.empty() && !matrix[0].empty());

        size_t m = matrix.size(), n = matrix.empty() ? 0 : matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n));
        dp[0] = matrix[0];
        for (size_t i = 1; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                dp[i][j] = matrix[i][j] + dp[i - 1][j];
                if (0 < j) {
                    dp[i][j] = std::min(dp[i][j], matrix[i][j] + dp[i - 1][j - 1]);
                }
                if (j + 1 < n) {
                    dp[i][j] = std::min(dp[i][j], matrix[i][j] + dp[i - 1][j + 1]);
                }
            }
        }

        return *std::min_element(dp[m - 1].begin(), dp[m - 1].end());
    }

    // Time: O(mn), Space: O(n)
    int dp2(vector<vector<int>>& matrix) {
        assert(!matrix.empty() && !matrix[0].empty());

        size_t m = matrix.size(), n = matrix.empty() ? 0 : matrix[0].size();

        vector<int> dp(matrix[0]);
        for (size_t i = 1; i < m; ++i) {
            int pre;
            for (size_t j = 0; j < n; ++j) {
                int tmp = dp[j];

                dp[j] = matrix[i][j] + dp[j];
                if (0 < j) {
                    dp[j] = std::min(dp[j], matrix[i][j] + pre);
                }
                if (j + 1 < n) {
                    dp[j] = std::min(dp[j], matrix[i][j] + dp[j + 1]);
                }

                pre = tmp;
            }
        }

        return *std::min_element(dp.begin(), dp.end());
    }

    // Time: O(mn), Space: O(1))
    int dp3(vector<vector<int>>& matrix) {
        assert(!matrix.empty() && !matrix[0].empty());

        size_t m = matrix.size(), n = matrix.empty() ? 0 : matrix[0].size();

        for (size_t i = 1; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                int cost = matrix[i - 1][j];
                if (0 < j) {
                    cost = std::min(cost, matrix[i - 1][j - 1]);
                }
                if (j + 1 < n) {
                    cost = std::min(cost, matrix[i - 1][j + 1]);
                }
                matrix[i][j] += cost;
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
