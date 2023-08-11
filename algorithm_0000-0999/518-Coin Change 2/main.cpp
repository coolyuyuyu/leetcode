class Solution {
public:
    // Time: O(n * amount * k), k = amount / min(coins)
    // Space: O(n * amount)
    int dp1(int amount, vector<int>& coins) {
        int n = coins.size();

        coins.insert(coins.begin(), 0);

        // dp[i][j] the number of combinations from coins[1:i] that make up that amount j
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1));
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= amount; ++j) {
                dp[i][j] = 0;
                for (int k = 0; 0 <= (j - coins[i] * k); ++k) {
                    dp[i][j] += dp[i - 1][j - coins[i] * k];
                }
            }
        }

        return dp[n][amount];
    }

    // Time: O(n * amount * k), k = amount / min(coins)
    // Space: O(n)
    int dp2(int amount, vector<int>& coins) {
        int n = coins.size();

        coins.insert(coins.begin(), 0);

        // dp[j]: the number of combinationsthat make up that amount j
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            vector<int> tmp = dp;
            for (int j = 1; j <= amount; ++j) {
                dp[j] = 0;
                for (int k = 0; 0 <= (j - coins[i] * k); ++k) {
                    dp[j] += tmp[j - coins[i] * k];
                }
            }
        }

        return dp[amount];
    }

    // Time: O(n * amount)
    // Space: O(n)
    int dp3(int amount, vector<int>& coins) {
        int n = coins.size();

        coins.insert(coins.begin(), 0);

        // dp[j]: the number of combinationsthat make up that amount j
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            vector<int> tmp = dp;
            for (int j = 1; j <= amount; ++j) {
                if (coins[i] <= j) {
                    dp[j] += dp[j - coins[i]];
                }
            }
        }

        return dp[amount];
    }

    int change(int amount, vector<int>& coins) {
        //return dp1(amount, coins);
        //return dp2(amount, coins);
        return dp3(amount, coins);
    }
};
