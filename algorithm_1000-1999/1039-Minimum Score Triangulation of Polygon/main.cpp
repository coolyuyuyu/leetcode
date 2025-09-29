class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();

        // dp[i][j]: the minimum score from vertex[i:j]
        int dp[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                dp[i][j] = INT_MAX / 3;
            }
        }
        for (int i = 0; i + 1 < n; ++i) {
            dp[i][i + 1] = 0;
        }
        for (int len = 3; len <= n; ++len) {
            for (int i = 0, j = i + len - 1; j < n; ++i, ++j) {
                for (int k = i + 1; k < j; ++k)
                dp[i][j] = std::min(dp[i][j], dp[i][k] + values[i] * values[j] * values[k] + dp[k][j]);
            }
        }
        return dp[0][n - 1];
    }
};

// 6-side convex
//   0  1
// 5      2
//   4   3
//
// side 0,5 pick 1
//     => [0:1] +  [1:5]
// side 0,5 pick 2
//     => [0:2] + [2:5]
// side 0,5 pick 3
//     => [0:3] + [3:5]
// side 0,5 pick 4
//     => [0:4] + [4:5]
