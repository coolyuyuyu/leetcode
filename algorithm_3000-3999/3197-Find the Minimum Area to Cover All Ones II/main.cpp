class Solution {
public:
    int minimumArea(vector<vector<int>>& grid, int r1, int c1, int r2, int c2) {
        int top = INT_MAX, btm = INT_MIN, lft = INT_MAX, rht = INT_MIN;
        bool any = false;
        for (int r = r1; r <= r2; ++r) {
            for (int c = c1; c <= c2; ++c) {
                if (grid[r][c] == 0) { continue; }
                any = true;
                top = std::min(top, r);
                btm = std::max(btm, r);
                lft = std::min(lft, c);
                rht = std::max(rht, c);
            }
        }
        if (!any) {
            return INT_MAX / 3;
        }

        return (btm - top + 1) * (rht - lft + 1);
    }

    int minimumSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        int ret = INT_MAX;
        for (int i = 1; i < m; ++i) {
            for (int j = i + 1; j < m; ++j) {
                int area1 = minimumArea(grid, 0, 0, i - 1, n - 1);
                int area2 = minimumArea(grid, i, 0, j - 1, n - 1);
                int area3 = minimumArea(grid, j, 0, m - 1, n - 1);
                ret = std::min(ret, area1 + area2 + area3);
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                int area1 = minimumArea(grid, 0, 0, i - 1, j - 1);
                int area2 = minimumArea(grid, 0, j, i - 1, n - 1);
                int area3 = minimumArea(grid, i, 0, m - 1, n - 1);
                ret = std::min(ret, area1 + area2 + area3);
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                int area1 = minimumArea(grid, 0, 0, i - 1, n - 1);
                int area2 = minimumArea(grid, i, 0, m - 1, j - 1);
                int area3 = minimumArea(grid, i, j, m - 1, n - 1);
                ret = std::min(ret, area1 + area2 + area3);
            }
        }
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int area1 = minimumArea(grid, 0, 0, m - 1, i - 1);
                int area2 = minimumArea(grid, 0, i, m - 1, j - 1);
                int area3 = minimumArea(grid, 0, j, m - 1, n - 1);
                ret = std::min(ret, area1 + area2 + area3);
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                int area1 = minimumArea(grid, 0, 0, m - 1, j - 1);
                int area2 = minimumArea(grid, 0, j, i - 1, n - 1);
                int area3 = minimumArea(grid, i, j, m - 1, n - 1);
                ret = std::min(ret, area1 + area2 + area3);
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                int area1 = minimumArea(grid, 0, 0, i - 1, j - 1);
                int area2 = minimumArea(grid, i, 0, m - 1, j - 1);
                int area3 = minimumArea(grid, 0, j, m - 1, n - 1);
                ret = std::min(ret, area1 + area2 + area3);
            }
        }

        return ret;
    }
};

// 1.      2.      3.
// ┌－┐    ┌┐┌┐    ┌－┐
// └－┘    └┘└┘    └－┘
// ┌－┐    ┌－┐    ┌┐┌┐
// └－┘    └－┘    └┘└┘
// ┌－┐
// └－┘
// 4.      5.      6.
// ┌┐┌┐┌┐  ┌ ┐┌┐   ┌┐┌ ┐
// └┘└┘└┘  │ │└┘   └┘│ │
//         │ │┌┐   ┌┐│ │
//         └ ┘└┘   └┘└ ┘
