class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        size_t n = grid.size();

        vector<vector<int>> ans(n - 2, vector<int>(n - 2));
        for (size_t i = 0; (i + 2) < n; ++i) {
            for (size_t j = 0; (j + 2) < n; ++j) {
                int maxVal = 0;
                for (size_t x = i; x < (i + 3); ++x) {
                    for (size_t y = j; y < (j + 3); ++y) {
                        if (maxVal < grid[x][y]) {
                            maxVal = grid[x][y];
                        }
                    }
                }
                ans[i][j] = maxVal;
            }
        }

        return ret;
    }
};
