class Solution {
public:
    // Time: O(n * amount * k), k = amount / min(coins)
    // Space: O(n * amount)
    int dp1(vector<int>& coins, int amount) {
        int n = coins.size();

        coins.insert(coins.begin(), 0);

        // dp[i][j] the fewest number of coins from coins[1:i] that make up that amount j
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1));
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = 0;
        }
        for (int j = 1; j <= amount; ++j) {
            dp[0][j] = INT_MAX / 2;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= amount; ++j) {
                dp[i][j] = INT_MAX / 2;
                for (int k = 0; 0 <= (j - coins[i] * k); ++k) {
                    dp[i][j] = std::min(dp[i][j], dp[i - 1][j - coins[i] * k] + k);
                }
            }
        }

        return dp[n][amount] < INT_MAX / 2 ? dp[n][amount] : -1;
    }

    // Time: O(n * amount * k), k = amount / min(coins)
    // Space: O(n)
    int dp2(vector<int>& coins, int amount) {
        int n = coins.size();

        coins.insert(coins.begin(), 0);

        // dp[j] the number of combinationsthat make up that amount j
        vector<int> dp(amount + 1);
        dp[0] = 0;
        for (int j = 1; j <= amount; ++j) {
            dp[j] = INT_MAX / 2;
        }
        for (int i = 1; i <= n; ++i) {
            vector<int> tmp = dp;
            for (int j = 1; j <= amount; ++j) {
                dp[j] = INT_MAX / 2;
                for (int k = 0; 0 <= (j - coins[i] * k); ++k) {
                    dp[j] = std::min(dp[j], tmp[j - coins[i] * k] + k);
                }
            }
        }

        return dp[amount] < INT_MAX / 2 ? dp[amount] : -1;
    }

    // Time: O(n * amount)
    // Space: O(n)
    int dp3(vector<int>& coins, int amount) {
        int n = coins.size();

        coins.insert(coins.begin(), 0);

        // dp[j] the number of combinationsthat make up that amount j
        vector<int> dp(amount + 1);
        dp[0] = 0;
        for (int j = 1; j <= amount; ++j) {
            dp[j] = INT_MAX / 2;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= amount; ++j) {
                if (coins[i] <= j) {
                    dp[j] = std::min(dp[j], dp[j - coins[i]] + 1);;
                }
            }
        }

        return dp[amount] < INT_MAX / 2 ? dp[amount] : -1;
    }

    int coinChange(vector<int>& coins, int amount) {
        //return dp1(coins, amount);
        //return dp2(coins, amount);
        return dp3(coins, amount);
    }
};
