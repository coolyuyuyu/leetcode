class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int a = 0;
        for (size_t x = 0, n = grid.size(); x < n; ++x) {
            int m1 = 0, m2 = 0;
            for (size_t y = 0; y < n; ++y) {
                // xy
                if (0 < grid[x][y]) {
                    a += 1;
                }

                // xz
                if (m1 < grid[x][y]) {
                    m1 = grid[x][y];
                }

                // yz
                if (m2 < grid[y][x]) {
                    m2 = grid[y][x];
                }
            }
            a += m1;
            a += m2;
        }

        return a;
    }
};
