class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        int n = coins.size();

        std::sort(coins.begin(), coins.end());

        long long ret = 0;

        long long presums[n];
        for (int i = 0; i < n; ++i) {
            presums[i] = (i > 0 ? presums[i - 1] : 0) + 1LL * coins[i][2] * (coins[i][1] - coins[i][0] + 1);
        }
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < n && coins[i][0] + k - 1 >= coins[j][1]) {
                ++j;
            }

            long long cntCoins = 0;
            if (j > i) {
                cntCoins += presums[j - 1] - (i > 0 ? presums[i - 1] : 0);
            }
            if (j < n) {
                cntCoins += std::max(0LL, 1LL * coins[j][2] * (coins[i][0] + k - 1 - coins[j][0] + 1));
            }

            ret = std::max(ret, cntCoins);
        }

        long long postsums[n];
        for (int i = n - 1; i >= 0; --i) {
            postsums[i] = ((i + 1 < n) ? postsums[i + 1] : 0) + 1LL * coins[i][2] * (coins[i][1] - coins[i][0] + 1);
        }
        for (int i = n - 1, j = n - 1; i >= 0; --i) {
            while (j >= 0 && coins[i][1] - k + 1 <= coins[j][0]) {
                --j;
            }

            long long cntCoins = 0;
            if (j < i) {
                cntCoins += postsums[j + 1] - ((i + 1 < n) ? postsums[i + 1] : 0);
            }
            if (j >= 0) {
                cntCoins += std::max(0LL, 1LL * coins[j][2] * (coins[j][1] - (coins[i][1] - k + 1) + 1));
            }

            ret = std::max(ret, cntCoins);
        }
        

        return ret;
    }
};
