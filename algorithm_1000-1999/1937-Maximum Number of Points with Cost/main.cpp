class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points.empty() ? 0 : points[0].size();

        long long dp[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = LLONG_MIN;
            }
        }
        for (int j = 0; j < n; ++j) {
            dp[0][j] = points[0][j];
        }

        for (int i = 1; i < m; ++i) {
            long long rollingMx = LLONG_MIN;
            for (int j = 0; j < n; ++j) {
                rollingMx = std::max(rollingMx, dp[i - 1][j] + j);
                dp[i][j] = std::max(dp[i][j], rollingMx - j + points[i][j]);
            }

            rollingMx = LLONG_MIN;
            for (int j = n; 0 < j--;) {
                rollingMx = std::max(rollingMx, dp[i - 1][j] - j);
                dp[i][j] = std::max(dp[i][j], rollingMx + j + points[i][j]);
            }
        }

        long long ret = LLONG_MIN;
        for (int j = 0; j < n; ++j) {
            ret = std::max(ret, dp[m - 1][j]);
        }

        return ret;
    }
};

// dp[i][j]: maximum the number of points can get from first to i rows and pick points from points[i][j]
// for (int i = 0; i < m; ++i) {
//     for (int j = 0; j < n; ++j) {
//         for (int k = 0; k < m; ++k) {
//             dp[i][j] = std::max(dp[i][j], dp[i - 1][k] - abs(j - k) + points[i][j]);
//         }
//     }
// }

// dp[i - 1][k] - abs(j - k) for k = 0, 1, ... n-1
// 1. dp[i - 1][k] - j + k for k = 0, 1, ..., j
// 2. dp[i - 1][k] + j - k for k = j, j+1, ..., n-1
