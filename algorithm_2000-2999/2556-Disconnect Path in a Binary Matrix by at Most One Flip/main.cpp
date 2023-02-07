class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        for (int r = m; 0 < r--;) {
            for (int c = n; 0 < c--;) {
                if ((r + 1) == m && (c + 1) == n) {
                    continue;
                }
                if (((r + 1) == m || grid[r + 1][c] == 0) && ((c + 1) == n || grid[r][c + 1] == 0)) {
                    grid[r][c] = 0;
                }
            }
        }
        if (grid[0][0] == 0) {
            return true;
        }

        int rBL = 0, cBL = 0; // btm-lft outermost path
        int rTR = 0, cTR = 0; // top-rht outermost path
        for (int k = 0; k < (m + n - 3); ++k) {
            if (((rBL + 1) < m) && grid[rBL + 1][cBL] == 1) {
                ++rBL;
            }
            else {
                ++cBL;
            }

            if (((cTR + 1) < n) && grid[rTR][cTR + 1] == 1) {
                ++cTR;
            }
            else {
                ++rTR;
            }

            if (rBL == rTR && cBL == cTR) {
                return true;
            }

        }

        return false;
    }
};

// 1. remove dead branch from grid[0][0] to grid[m-1][n-1]
// Walk from grid[0][0] to grid[m-1][n-1], it is possible to end into a dead branch.
//     => dp from grid[m-1][n-1] to grid[0][0] to remove dead branch

// 2. find the cut point
// possible cut:
//     => every path from grid[0][0] to grid[m-1][n-1] intersect at a (or multiple) point.
// Check two outermost paths:
//     => one path lean to top-right corner as possible
//     => one path lean to bottom-left corner as possible
//     => all other paths exist in between
//     => the cut point is where two outermost paths intersect,
