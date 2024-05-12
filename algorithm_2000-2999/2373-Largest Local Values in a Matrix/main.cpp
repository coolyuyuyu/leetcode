class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ret(n - 2, vector<int>(n - 2));
        for (int r = 0; r + 2 < n; ++r) {
            for (int c = 0; c + 2 < n; ++c) {
                int mx = INT_MIN;
                for (int i = r; i < r + 3; ++i) {
                    for (int j = c; j < c + 3; ++j) {
                        mx = std::max(mx, grid[i][j]);
                    }
                }
                ret[r][c] = mx;
            }
        }

        return ret;
    }
};
