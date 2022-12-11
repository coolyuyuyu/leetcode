class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();
        for (int i = 0; i < m; ++i) {
            std::sort(grid[i].begin(), grid[i].end());
        }

        int ret = 0;
        for (int j = 0; j < n; ++j) {
            int maxVal = INT_MIN;
            for (int i = 0; i < m; ++i) {
                maxVal = std::max(maxVal, grid[i][j]);
            }

            ret += maxVal;
        }

        return ret;
    }
};
