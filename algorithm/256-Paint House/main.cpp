class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        size_t n = costs.size();
        if (n == 0) {
            return 0;
        }

        vector<vector<int>> dp(n, vector<int>(3));
        dp[0] = costs[0];
        for (size_t i = 1; i < n; ++i) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i][2];
        }

        return *min_element(dp[n - 1].begin() , dp[n - 1].end());
    }
};