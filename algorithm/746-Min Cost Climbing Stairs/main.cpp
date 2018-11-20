class Solution {
public:
    int minCostClimbingStairs_v0(vector<int>& cost) {
        vector<int> dp(cost.size() + 1);
        dp[0] = 0;
        dp[1] = 0;
        for (size_t i = 2; i <= cost.size(); ++i) {
            dp[i] = min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
        }

        return dp[cost.size()];
    }

    int minCostClimbingStairs_v1(vector<int>& cost) {
        int x = 0, y = 0, z = 0;
        for (size_t i = 2; i <= cost.size(); ++i) {
            z = min(x + cost[i - 2], y + cost[i - 1]);
            x = y;
            y = z;
        }

        return z;
    }

    int minCostClimbingStairs(vector<int>& cost) {        
        return minCostClimbingStairs_v1(cost);
    }
};
