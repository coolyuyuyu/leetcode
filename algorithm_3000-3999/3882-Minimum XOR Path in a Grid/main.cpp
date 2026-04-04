class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        // dp[r][c][val]: whether it is possible to reach (r, c) with XOR value almong all valid paths
        bitset<1024> dp[m][n];

        dp[0][0].reset();
        dp[0][0][grid[0][0]] = true;
        for (int r = 1, val = grid[0][0]; r < m; ++r) {
            dp[r][0].reset();
            val ^= grid[r][0];
            dp[r][0][val] = true;
        }
        for (int c = 1, val = grid[0][0]; c < n; ++c) {
            dp[0][c].reset();
            val ^= grid[0][c];
            dp[0][c][val] = true;
        }

        for (int r = 1; r < m; ++r) {
            for (int c = 1; c < n; ++c) {
                for (int val = 0; val < 1024; ++val) {
                    dp[r][c][val] = (dp[r - 1][c][val ^ grid[r][c]] || dp[r][c - 1][val ^ grid[r][c]]);
                }
            }
        }

        int ret;
        for (int val = 0; val < 1024; ++val) {
            if (dp[m - 1][n - 1][val]) {
                ret = val;
                break;
            }
        }

        return ret;
    }
};
