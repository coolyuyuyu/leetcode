class Solution {
public:
    vector<vector<int>> minScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        pair<int, int> pos[m * n];
        for (int r = 0, i = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                pos[i++] = {r, c};
            }
        }
        std::sort(pos, pos + (m * n), [&](const auto& pos1, const auto& pos2) { return grid[pos1.first][pos1.second] < grid[pos2.first][pos2.second]; });

        int rowMax[m], colMax[n];
        std::fill(rowMax, rowMax + m, 0);
        std::fill(colMax, colMax + n, 0);

        vector<vector<int>> ret(m, vector<int>(n));
        for (int i = 0; i < m * n; ++i) {
            const auto& [r, c] = pos[i];
            ret[r][c] = std::max(rowMax[r], colMax[c]) + 1;
            rowMax[r] = colMax[c] = ret[r][c];
        }

        return ret;
    }
};
