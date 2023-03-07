class Solution {
public:
    int M = 1e9 + 7;

    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size();

        types.insert(types.begin(), {0, 0});

        // dp[i][j]: the number of ways you can earn exactly j points in the exam from first i types
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= target; ++j) {
                for (int k = 0; k <= types[i][0] && (k * types[i][1]) <= j; ++k) {
                    dp[i][j] += dp[i - 1][j - k * types[i][1]];
                    dp[i][j] %= M;
                }
            }
        }

        return dp[n][target];
    }
};
