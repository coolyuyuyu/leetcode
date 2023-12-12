class Solution {
public:
    vector<vector<int>> byBFS(vector<vector<int>>& mat) {
        vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        int m = mat.size(), n = mat.empty() ? 0 : mat[0].size();

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
        for (int dist = 1; !q.empty(); ++dist) {
            for (int i = q.size(); 0 < i--;) {
                auto [r, c] = q.front();
                q.pop();
                for (const auto& [dr, dc] : dirs) {
                    int x = r + dr, y = c + dc;
                    if (x < 0 || m <= x || y < 0 || n <= y) { continue; }
                    if (ret[x][y] >= 0) { continue; }

                    ret[x][y] = dist;
                    q.emplace(x, y);
                }
            }
        }

        return ret;
    }

    vector<vector<int>> byDP(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat.empty() ? 0 : mat[0].size();

        // dp[r][c]: the distance of the nearest 0 for cell (r, c)
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                dp[r][c] = std::min({
                    mat[r][c] == 0 ? 0 : INT_MAX / 2,
                    0 < r ? dp[r - 1][c] + 1 : INT_MAX / 2,
                    0 < c ? dp[r][c - 1] + 1 : INT_MAX / 2});
            }
        }
        for (int r = m; 0 < r--;) {
            for (int c = n; 0 < c--;) {
                dp[r][c] = std::min({
                    dp[r][c],
                    mat[r][c] == 0 ? 0 : INT_MAX / 2,
                    r + 1 < m ? dp[r + 1][c] + 1 : INT_MAX / 2,
                    c + 1 < n ? dp[r][c + 1] + 1 : INT_MAX / 2});
            }
        }

        return dp;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        //return byBFS(mat);
        return byDP(mat);
    }
};
