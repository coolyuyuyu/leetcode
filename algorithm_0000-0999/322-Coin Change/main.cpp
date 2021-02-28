class Solution {
public:
    int coinChange(const vector<int>& coins, int amount, vector<int>& cache) {
        assert(0 <= amount);
        if (amount == 0) {
            return 0;
        }
        else if (cache[amount] != 0) {
            return cache[amount];
        }

        int ans = 0;
        for (int coin : coins)
        {
            if (coin <= amount) {
                int subAns = coinChange(coins, amount - coin, cache);
                if (subAns != -1) {
                    ans = min(ans == 0 ? INT_MAX : ans, 1 + subAns);
                }
            }
        }
        ans = (ans == 0 ? -1 : ans);
        cache[amount] = ans;

        return ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> cache(amount + 1, 0);
        return coinChange(coins, amount, cache);
    }
};