class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        int ret = m * (1 << (n - 1));
        for (int c = 1; c < n; ++c) {
            int cnt = 0;
            for (int r = 0; r < m; ++r) {
                cnt += (grid[r][c] == grid[r][0] ? 1 : 0);
            }
            ret += std::max(cnt, m - cnt) << (n - c - 1);
        }

        return ret;
    }
};
