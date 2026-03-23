class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for (int r = 0; r * 2 < k; ++r) {
            for (int c = 0; c < k; ++c) {
                std::swap(grid[x + r][y + c], grid[x + k - r - 1][y + c]);
            }
        }

        return grid;
    }
};
