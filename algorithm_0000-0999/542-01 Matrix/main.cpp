class Solution {
public:
    vector<vector<int>> bfs(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat.empty() ? 0 : mat[0].size();
        vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

        vector<vector<int>> ret(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (mat[r][c] == 0) {
                    ret[r][c] = 0;
                    q.emplace(r, c);
                }
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (const auto& [dr, dc] : dirs) {
                int x = r + dr, y = c + dc;
                if (x < 0 || m <= x || y < 0 || n <= y) { continue; }
                if (0 <= ret[x][y]) { continue; }

                ret[x][y] = ret[r][c] + 1;
                q.emplace(x, y);
            }
        }

        return ret;
    }

    vector<vector<int>> dynamicProgramming(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat.empty() ? 0 : mat[0].size();

        // dp[r][c]: the distance of the nearest 0 for cell (r, c)
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = mat[0][0] == 0 ? 0 : (INT_MAX / 2);
        for (int r = 1; r < m; ++r) {
            dp[r][0] = mat[r][0] == 0 ? 0 : (dp[r - 1][0] + 1);
        }
        for (int c = 1; c < n; ++c) {
            dp[0][c] = mat[0][c] == 0 ? 0 : (dp[0][c - 1] + 1);
        }
        for (int r = 1; r < m; ++r) {
            for (int c = 1; c < n; ++c) {
                dp[r][c] = mat[r][c] == 0 ? 0 : (std::min(dp[r - 1][c], dp[r][c - 1]) + 1);
            }
        }

        for (int r = m - 1; 0 < r--;) {
            dp[r][n - 1] = std::min(dp[r][n - 1], dp[r + 1][n - 1] + 1);
        }
        for (int c = n - 1; 0 < c--;) {
            dp[m - 1][c] = std::min(dp[m - 1][c], dp[m - 1][c + 1] + 1);
        }
        for (int r = m - 1; 0 < r--;) {
            for (int c = n - 1; 0 < c--;) {
                dp[r][c] = std::min({dp[r][c], dp[r + 1][c] + 1, dp[r][c + 1] + 1});
            }
        }

        return dp;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        //return bfs(mat);
        return dynamicProgramming(mat);
    }
};
