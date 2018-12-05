class Solution {
public:
    int minCostClimbingStairs1(const vector<int>& costs) {
        size_t n = costs.size();
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 0;
        for (size_t i = 2; i <= n ; ++i) {
            dp[i] = min(dp[i - 2] + costs[i - 2], dp[i - 1] + costs[i - 1]);
        }
        return dp[n];
    }

    int minCostClimbingStairs2(const vector<int>& costs) {
        int x = 0, y = 0;
        for (size_t i = 2; i <= costs.size() ; ++i) {
            int tmp = y;
            y = min(x + costs[i - 2], y + costs[i - 1]);
            x = tmp;
        }

        return y;
    }

    int minCostClimbingStairs(vector<int>& costs) {
        //return minCostClimbingStairs1(costs);

        return minCostClimbingStairs2(costs);
    }
};