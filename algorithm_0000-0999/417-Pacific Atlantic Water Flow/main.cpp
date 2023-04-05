class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        size_t m = heights.size(), n = heights.empty() ? 0 : heights[0].size();

        vector<vector<bool>> pac(m, vector<bool>(n, false)), atl(m, vector<bool>(n, false));
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        std::function<void(int, int, vector<vector<bool>>&)> dfs = [m, n, &heights, &dirs, &dfs](int r, int c, vector<vector<bool>>& sea) {
            if (sea[r][c]) {
                return;
            }

            sea[r][c] = true;
            for (const auto& [dR, dC] : dirs) {
                int rNew = r + dR, cNew = c + dC;
                if (rNew < 0 || m <= rNew || cNew < 0 || n <= cNew) {
                    continue;
                }
                if (heights[rNew][cNew] < heights[r][c]) {
                    continue;
                }
                dfs(rNew, cNew, sea);
            }
        };
        for (int r = 0; r < m; ++r) {
            dfs(r, 0, pac);
            dfs(r, n - 1, atl);
        }
        for (int c = 0; c < n; ++c) {
            dfs(0, c, pac);
            dfs(m - 1, c, atl);
        }

        vector<vector<int>> ret;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (pac[r][c] && atl[r][c]) {
                    ret.push_back({r, c});
                }
            }

        }

        return ret;
    }
};
