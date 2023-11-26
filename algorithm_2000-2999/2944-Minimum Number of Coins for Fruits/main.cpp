class Solution {
public:
    // Time: O(n^2)
    int dp1(vector<int>& prices) {
        int n = prices.size();

        prices.insert(prices.begin(), 0);

        // dp[i]: the minimum number of coins to acqurire fruits[i:n]
        int dp[n + 2];
        dp[n + 1] = 0;

        for (int i = n; i >= 1; --i) {
            int x = INT_MAX;
            for (int j = i + 1; j <= std::min(i * 2 + 1, n + 1); ++j) {
                x = std::min(x, dp[j]);
            }
            dp[i] = prices[i] + x;
        }

        return dp[1];
    }

    // Time: O(n)
    int dp2(vector<int>& prices) {
        int n = prices.size();

        prices.insert(prices.begin(), 0);

        // dp[i]: the minimum number of coins to acqurire fruits[i:n]
        int dp[n + 2];
        dp[n + 1] = 0;

        deque<int> dq;
        dq.push_back(n + 1);

        for (int i = n; i >= 1; --i) {
            while (!dq.empty() && (2 * i + 1) < dq.front()) {
                dq.pop_front();
            }

            dp[i] = prices[i] + dp[dq.front()];

            while (!dq.empty() && dp[i] < dp[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        return dp[1];
    }

    int minimumCoins(vector<int>& prices) {
        //return dp1(prices);
        return dp2(prices);
    }
};
