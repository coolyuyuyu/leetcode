class Solution {
public:
    // Time: O(n^2)
    int dp1(vector<int>& prices) {
        int n = prices.size();
        prices.insert(prices.begin(), INT_MAX);

        // dp[i][0]: the minimum number of coins to acquire fruits[1:i] and we get fruit[i] for free.
        // dp[i][1]: the minimum number of coins to acquire fruits[1:i] and we get pay for fruit[i].
        int dp[n + 1][2];
        dp[0][0] = 0;
        dp[0][1] = prices[0];

        for (int i = 1; i <= n; ++i) {
            dp[i][0] = INT_MAX;
            for (int j = i - 1; j >= 0 && j * 2 >= i; --j) {
                dp[i][0] = std::min(dp[i][0], dp[j][1]);
            }

            dp[i][1] = std::min(dp[i - 1][0], dp[i - 1][1]) + prices[i];
        }

        return std::min(dp[n][0], dp[n][1]);
    }

    // Time: O(n)
    int dp2(vector<int>& prices) {
        int n = prices.size();
        prices.insert(prices.begin(), INT_MAX);

        // dp[i][0]: the minimum number of coins to acquire fruits[1:i] and we get fruit[i] for free.
        // dp[i][1]: the minimum number of coins to acquire fruits[1:i] and we get pay for fruit[i].
        int dp[n + 1][2];
        dp[0][0] = 0;
        dp[0][1] = prices[0];

        deque<int> dq;
        dq.push_back(0);

        for (int i = 1; i <= n; ++i) {
            while (!dq.empty() && dq.front() * 2 < i) {
                dq.pop_front();
            }

            dp[i][0] = dq.empty() ? INT_MAX : dp[dq.front()][1];
            dp[i][1] = std::min(dp[i - 1][0], dp[i - 1][1]) + prices[i];

            while (!dq.empty() && dp[dq.back()][1] >= dp[i][1]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        return std::min(dp[n][0], dp[n][1]);
    }

    int minimumCoins(vector<int>& prices) {
        //return dp1(prices);
        return dp2(prices);
    }
};
