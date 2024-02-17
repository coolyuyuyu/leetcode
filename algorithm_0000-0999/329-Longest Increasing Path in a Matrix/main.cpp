class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix.empty() ? 0 : matrix[0].size();

        // dp[r][c]: the length of the longest increasing path starting from (r, c)
        int dp[m][n];
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                dp[r][c] = 0;
            }
        }

        vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        std::function<int(int, int)> f = [&](int r, int c) {
            int& ret = dp[r][c];
            if (ret > 0) {
                return ret;
            }

            ret = 1;
            for (const auto& [dr, dc] : dirs) {
                int x = r + dr, y = c + dc;
                if (x < 0 || m <= x || y < 0 || n <= y) { continue; }
                if (matrix[x][y] <= matrix[r][c]) { continue; }
                ret = std::max(ret, 1 + f(x, y));
            }

            return ret;
        };

        int ret = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                ret = std::max(ret, f(r, c));
            }
        }

        return ret;
    }
};
