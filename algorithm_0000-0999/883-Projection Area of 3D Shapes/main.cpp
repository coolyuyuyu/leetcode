class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int area = 0;

        size_t n = grid.size();
        for (size_t i = 0; i < n; ++i) {
            int maxRowHeight = grid[i][0];
            int maxColHeight = grid[0][i];
            for (size_t j = 0; j < n; ++j) {
                if (0 < grid[i][j]) {
                    ++area;

                    if (maxRowHeight < grid[i][j]) {
                        maxRowHeight = grid[i][j];
                    }
                }

                if (maxColHeight < grid[j][i]) {
                    maxColHeight = grid[j][i];
                }
            }

            area += maxRowHeight;
            area += maxColHeight;
        }

        return area;
    }
};