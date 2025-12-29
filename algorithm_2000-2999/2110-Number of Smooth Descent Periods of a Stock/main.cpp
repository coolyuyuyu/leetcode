class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();

        prices.insert(prices.begin(), LLONG_MAX);

        // dp[i] the number of smooth descent periods ending at day i
        long long dp[n + 1];
        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            dp[i] = (prices[i - 1] - 1 == prices[i] ? dp[i - 1] : 0) + 1;
        }

        long long ret = 0;
        for (int i = 1; i <= n; ++i) {
            ret += dp[i];
        }

        return ret;
    }
};
