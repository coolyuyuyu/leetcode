class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        int n = coins.size();

        std::sort(coins.begin(), coins.end());

        long long ret = 0;
        for (long i = 0, j = 0, sum = 0; i < n; ++i) {
            int end = coins[i][0] + k - 1;
            for (; j < n && end >= coins[j][1]; ++j) {
                sum += 1LL * coins[j][2] * (coins[j][1] - coins[j][0] + 1);
            }

            long long extra = 0;
            if (j < n && end >= coins[j][0]) {
                extra += 1LL * coins[j][2] * (end - coins[j][0] + 1);
            }

            ret = std::max(ret, sum + extra);

            sum -= 1LL * coins[i][2] * (coins[i][1] - coins[i][0] + 1);
        }

        for (long long i = n - 1, j = n - 1, sum = 0; i >= 0; --i) {
            int end = coins[i][1] - k + 1;
            for (; j >= 0 && end <= coins[j][0]; --j) {
                sum += 1LL * coins[j][2] * (coins[j][1] - coins[j][0] + 1);
            }

            long long extra = 0;
            if (j >= 0 && end <= coins[j][1]) {
                extra += 1LL * coins[j][2] * (coins[j][1] - end + 1);
            }

            ret = std::max(ret, sum + extra);

            sum -= 1LL * coins[i][2] * (coins[i][1] - coins[i][0] + 1);
        }

        return ret;
    }
};
