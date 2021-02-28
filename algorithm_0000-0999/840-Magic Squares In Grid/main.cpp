class Solution {
public:
    
    bool checkMagicSquare(const vector<vector<int>>& grid, size_t x, size_t y) {
        if (grid[x][y] != 5) {
            return false;
        }

        bool repeated[10] = { false };
        for (int i = -1; i < 2; ++i) {
            int rowSum = 0, colSum = 0;
            for (int j = -1; j < 2; ++j) {
                if (grid[x + i][y + j] < 1 || 9 < grid[x + i][y + j]) {
                    return false;
                }

                rowSum += grid[x + i][y + j];
                colSum += grid[x + j][y + i];

                if (repeated[grid[x + i][y + j]]) {
                    return false;
                }
                repeated[grid[x + i][y + j]] = true;
            }

            if (rowSum != 15 || colSum != 15) {
                return false;
            }
        }

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        size_t rowCnt = grid.size();
        size_t colCnt = grid.front().size();

        size_t cnt = 0;
        for (size_t row = 1; row + 1< rowCnt; ++row) {
            for (size_t col = 1; col + 1 < colCnt; ++col) {
                if (checkMagicSquare(grid, row, col)) {
                    ++cnt;
                }
            }
        }

        return cnt;
    }
};