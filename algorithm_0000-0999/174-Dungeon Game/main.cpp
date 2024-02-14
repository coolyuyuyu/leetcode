class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon.empty() ? 0 : dungeon[0].size();

        // dp[r][c]: the knight's minimum initial health such that knight can reach the destination from (r, c) after he digested dungeon[r][c].
        int dp[m][n];
        for (int r = m; 0 < r--;) {
            for (int c = n; 0 < c--;) {
                if (r == m - 1 && c == n - 1) {
                    dp[r][c] = 1 ;
                }
                else {
                    dp[r][c] = std::min(
                        r + 1 < m ? dp[r + 1][c] - dungeon[r + 1][c] : INT_MAX,
                        c + 1 < n ? dp[r][c + 1] - dungeon[r][c + 1] : INT_MAX);
                }
                dp[r][c] = std::max(dp[r][c], 1);
            }
        }

        dp[0][0] = dp[0][0] - dungeon[0][0];
        dp[0][0] = std::max(dp[0][0], 1);

        return dp[0][0];
    }
};
