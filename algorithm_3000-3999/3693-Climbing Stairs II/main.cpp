class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        costs.insert(costs.begin(), 0);

        // dp[i]: the minimum total cost to reach step i
        int dp[n + 1];
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = INT_MAX / 2;
        }
        for (int j = 1; j <= n; ++j) {
            for (int i = j - 1; i >= j - 3 && i >= 0; i--) {
                dp[j] = std::min(dp[j], dp[i] + costs[j] + (j - i) * (j - i));
            }
        }

        return dp[n];
    }
};
