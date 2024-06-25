class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        int top = INT_MAX, btm = INT_MIN, lft = INT_MAX, rht = INT_MIN;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 0) { continue; }
                top = std::min(top, r);
                btm = std::max(btm, r);
                lft = std::min(lft, c);
                rht = std::max(rht, c);
            }
        }

        return (btm - top + 1) * (rht - lft + 1);
    }
};
