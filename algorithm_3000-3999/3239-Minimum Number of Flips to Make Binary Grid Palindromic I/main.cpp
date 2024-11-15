class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        int ret1 = 0;
        for (int r = 0; r < m; ++r) {
            for (int lft = 0, rht = n - 1; lft < rht; ++lft, --rht) {
                if (grid[r][lft] != grid[r][rht]) {
                    ++ret1;
                }
            }
        }

        int ret2 = 0;
        for (int c = 0; c < n; ++c) {
            for (int top = 0, btm = m - 1; top < btm; ++top, --btm) {
                if (grid[top][c] != grid[btm][c]) {
                    ++ret2;
                }
            }
        }

        return std::min(ret1, ret2);
    }
};
