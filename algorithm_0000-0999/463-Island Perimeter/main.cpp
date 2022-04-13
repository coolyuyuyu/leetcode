class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int p = 0;
        size_t rowCnt = grid.size(), colCnt = grid.empty() ? 0 : grid.front().size();
        for (size_t r = 0; r < rowCnt; ++r) {
            for (size_t c = 0; c < colCnt; ++c) {
                if (grid[r][c]) {
                    p += 4;
                    if (0 < c && grid[r][c - 1]) {
                        p -= 2;
                    }
                    if (0 < r && grid[r - 1][c]) {
                        p -= 2;
                    }
                }
            }
        }

        return p;
    }
};
