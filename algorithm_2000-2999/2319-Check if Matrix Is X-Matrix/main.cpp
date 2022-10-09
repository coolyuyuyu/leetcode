class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        size_t n = grid.size();
        for (size_t row = 0; row < n; ++row) {
            for (size_t col = 0; col < n; ++col) {
                if (row == col || (row + col + 1) == n) {
                    if (grid[row][col] == 0) {
                        return false;
                    }
                }
                else {
                    if (grid[row][col] != 0) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
