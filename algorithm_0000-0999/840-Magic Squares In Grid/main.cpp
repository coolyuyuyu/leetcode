class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        std::function<bool(int, int)> check = [&](int r, int c) {
            std::bitset<10> repeated;
            int dSum1 = 0, dSum2 = 0;
            for (int i = 0; i < 3; ++i) {
                int rSum = 0, cSum = 0;
                for (int j = 0; j < 3; ++j) {
                    if (grid[r + i][c + j] < 0 || grid[r + i][c + j] > 9) { return false; }
                    if (repeated[grid[r + i][c + j]]) { return false; }

                    repeated[grid[r + i][c + j]] = 1;
                    rSum += grid[r + i][c + j];
                    cSum += grid[r + j][c + i];
                }
                if (rSum != 15 || cSum != 15) { return false; }

                dSum1 += grid[r + i][c + i];
                dSum2 += grid[r + i][c + 2 - i];
            }
            if (repeated.count() != 9) { return false; }
            if (dSum1 != 15 || dSum2 != 15) { return false; }

            return true;
        };

        int ret = 0;
        for (int r = 0; r + 2 < m; ++r) {
            for (int c = 0; c + 2 < n; ++c) {
                if (check(r, c)) {
                    ++ret;
                }
            }
        }

        return ret;
    }
};
