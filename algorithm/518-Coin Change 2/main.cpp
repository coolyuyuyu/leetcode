class Solution {
public:
    // Time(amount, size_of_coins) = O(amount * size_of_coins), Space(amount, size_of_coins) = O(amount * size_of_coins)
    size_t changeDpV1(int amount, const vector<int>& coins) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= coins.size(); ++i) {
            dp[i][0] = 1;
            for (int j = 1; j <= amount; ++j) {
                dp[i][j] = dp[i - 1][j] + (coins[i - 1] <= j ? dp[i][j - coins[i - 1]] : 0);
            }
        }
        return dp.back().back();
    }

    // Time(amount, size_of_coins) = O(amount * size_of_coins), Space(amount, size_of_coins) = O(amount)
    size_t changeDpV2(int amount, const vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= coins.size(); ++i) {
            for (int j = 1; j <= amount; ++j) {
                dp[j] = dp[j] + (coins[i - 1] <= j ? dp[j - coins[i - 1]] : 0);
            }
        }
        return dp.back();
    }

    size_t change(int amount, const vector<int>& coins) {
        //return changeDpV1(amount, coins);

        return changeDpV2(amount, coins);
    }
};