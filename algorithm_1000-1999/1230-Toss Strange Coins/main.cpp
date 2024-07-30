class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();

        prob.insert(prob.begin(), 0.0);

        // dp[i][j]: the probability that the j coins facing heads from first i tosses
        double dp[n + 1][target + 1];
        dp[0][0] = 1.0;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = dp[i - 1][0] * (1 - prob[i]);
        }
        for (int j = 1; j <= target; ++j) {
            dp[j - 1][j] = 0.0;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= std::min(i, target); ++j) {
                dp[i][j] = dp[i - 1][j] * (1.0 - prob[i]) + dp[i - 1][j - 1] * prob[i];
            }
        }

        return dp[n][target];
    }
};
