class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        prices.insert(prices.begin(), 0);

        // dp[i][j][0]: the maximum profit from prices[1:i], complete j transaction and hold stock.
        // dp[i][j][1]: the maximum profit from prices[1:i], complete j transaction and sold stock.
        int dp[n + 1][k + 1][2];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                dp[i][j][0] = dp[i][j][1] = INT_MIN / 2;
            }
        }
        dp[0][0][1] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i][0][1] = 0;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= std::min(i, k); ++j) {
                dp[i][j][0] = std::max(dp[i - 1][j][0], dp[i - 1][j - 1][1] - prices[i]);
                dp[i][j][1] = std::max(dp[i - 1][j][1], dp[i - 1][j][0] + prices[i]);
            }
        }

        int ret = 0;
        for (int j = 1; j <= k; ++j) {
            ret = std::max(ret, dp[n][j][1]);
        }

        return ret;
    }
};
