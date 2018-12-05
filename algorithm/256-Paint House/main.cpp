class Solution {
public:
    int minCost1(const vector<vector<int>>& costs) {
        if (costs.empty()) {
            return 0;
        }

        size_t n = costs.size();
        vector<vector<int>> dp(n, vector<int>(3));
        dp[0] = costs[0];
        for (size_t i = 1; i < n; ++i) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i][2];
        }

        return min(min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);
    }

    int minCost2(const vector<vector<int>>& costs) {
        if (costs.empty()) {
            return 0;
        }

        size_t n = costs.size();
        vector<int> dp(costs[0]);
        for (size_t i = 1; i < n; ++i) {
            int r = min(dp[1], dp[2]) + costs[i][0];
            int b = min(dp[0], dp[2]) + costs[i][1];
            int g = min(dp[0], dp[1]) + costs[i][2];
            dp = {r, b, g};
        }

        return min(min(dp[0], dp[1]), dp[2]);
    }

    int minCost(vector<vector<int>>& costs) {
        //return minCost1(costs);

        return minCost2(costs);
    }
};