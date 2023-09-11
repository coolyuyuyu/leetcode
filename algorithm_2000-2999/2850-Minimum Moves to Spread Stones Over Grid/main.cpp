class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        std::function<int()> dfs = [&]() {
            int ret = INT_MAX;
            for (int r1 = 0; r1 < 3; ++r1) {
                for (int c1 = 0; c1 < 3; ++c1) {
                    if (grid[r1][c1] == 0) {
                        for (int r2 = 0; r2 < 3; ++r2) {
                            for (int c2 = 0; c2 < 3; ++c2) {
                                if (grid[r2][c2] > 1) {
                                    ++grid[r1][c1];
                                    --grid[r2][c2];
                                    ret = std::min(ret, dfs() + abs(r2 - r1) + abs(c2 - c1));
                                    ++grid[r2][c2];
                                    --grid[r1][c1];
                                }
                            }
                        }
                    }
                }
            }

            return ret == INT_MAX ? 0 : ret;
        };

        return dfs();
    }
};
