class Solution {
public:
    int M = 1e9 + 7;
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<long long>> dpMin(m, vector<long long>(n)); // dpMin[i][j]: the minimum product subarray ending at [i,j]
        vector<vector<long long>> dpMax(m, vector<long long>(n)); // dpMax[i][j]: the maximum product subarray ending at [i,j]
        dpMin[0][0] = dpMax[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i) {
            std::tie(dpMin[i][0], dpMax[i][0]) = std::minmax(
                {
                    dpMax[i - 1][0] * grid[i][0],
                    dpMin[i - 1][0] * grid[i][0],
                });
        }
        for (int j = 1; j < n; ++j) {
            std::tie(dpMin[0][j], dpMax[0][j]) = std::minmax(
                {
                    dpMax[0][j - 1] * grid[0][j],
                    dpMin[0][j - 1] * grid[0][j],
                });
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                std::tie(dpMin[i][j], dpMax[i][j]) = std::minmax(
                    {
                        dpMax[i - 1][j] * grid[i][j],
                        dpMin[i - 1][j] * grid[i][j],
                        dpMax[i][j - 1] * grid[i][j],
                        dpMin[i][j - 1] * grid[i][j],
                    });
            }
        }

        if (dpMax[m - 1][n - 1] < 0) {
            return -1;
        }
        return dpMax[m - 1][n - 1] % M;
    }
};
