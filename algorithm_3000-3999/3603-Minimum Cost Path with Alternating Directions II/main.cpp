class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        // dp[r][c]: the minimum total cost required to reach (r, c)
        long long dp[m][n];
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                dp[r][c] = LLONG_MAX / 2;
            }
        }

        dp[0][0] = 1;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (r == 0 && c == 0) { continue; }

                int curEntryCost = (r + 1) * (c + 1);
                if (r > 0) {
                    int preWaitCost = (r + c > 1 ? waitCost[r - 1][c] : 0);
                    dp[r][c] = std::min(dp[r][c], dp[r - 1][c] + preWaitCost + curEntryCost);
                }
                if (c > 0) {
                    int preWaitCost = (r + c > 1 ? waitCost[r][c - 1] : 0);
                    dp[r][c] = std::min(dp[r][c], dp[r][c - 1] + preWaitCost + curEntryCost);
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
