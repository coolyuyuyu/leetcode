class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();

        prob.insert(prob.begin(), 0.0);

        // dp[i][j]: for the first i toss, j coins facing head
        vector<vector<double>> dp(n + 1, vector<double>(target + 1,0.0));
        dp[0][0] = 1.0;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = dp[i - 1][0] * (1 - prob[i]);
        }
        for (int j = 1; j <= target; ++j) {
            for (int i = j; i <= n; ++i) {
                dp[i][j] = dp[i - 1][j - 1] * (prob[i]) + dp[i-1][j] * (1 - prob[i]);
            }
        }

        return dp[n][target];
    }
};
