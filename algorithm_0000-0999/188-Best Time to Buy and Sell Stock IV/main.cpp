class Solution {
public:
    // Space: O(nk)
    int dp1(int k, vector<int>& prices) {
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
            for (int j = 1; j <= k; ++j) {
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

    // Space: O(k)
    int dp2(int k, vector<int>& prices) {
        int n = prices.size();
        if ((n / 2) <= k) {
            // infinite transaction
            // 122. Best Time to Buy and Sell Stock II

            int ret = 0;
            for (int i = 1; i < n; ++i) {
                if (prices[i - 1] < prices[i]) {
                    ret += (prices[i] - prices[i - 1]);
                }
            }

            return ret;
        }

        prices.insert(prices.begin(), 0);

        // hold[j]: the maximum profit so far, complete j transaction and hold stock.
        // sold[j]: the maximum profit so far, complete j transaction and sold stock.
        int hold[k + 1];
        int sold[k + 1];
        for (int j = 0; j <= k; ++j) {
            hold[j] = sold[j] = INT_MIN / 2;
        }
        sold[0] = 0;

        int tmpHold[k + 1];
        int tmpSold[k + 1];
        for (int i = 1; i <= n; ++i) {
            std::copy(hold, hold + k + 1, tmpHold);
            std::copy(sold, sold + k + 1, tmpSold);
            for (int j = 1; j <= k; ++j) {
                hold[j] = std::max(tmpHold[j], tmpSold[j - 1] - prices[i]);
                sold[j] = std::max(tmpSold[j], tmpHold[j] + prices[i]);
            }
        }

        int ret = 0;
        for (int j = 1; j <= k; ++j) {
            ret = std::max(ret, sold[j]);
        }

        return ret;
    }

    int maxProfit(int k, vector<int>& prices) {
        //return dp1(k, prices);
        return dp2(k, prices);
    }
};
