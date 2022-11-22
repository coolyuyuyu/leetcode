class Solution {
public:
    int dp_topDown(int n, vector<int>& cache) {
        if (cache.size() <= n) {
            cache.resize(n + 1, INT_MAX);
        }

        if (cache[n] != INT_MAX) {
            return cache[n];
        }

        for (int i = 1; (i * i) <= n; ++i) {
            cache[n] = std::min(cache[n], dp_topDown(n - i * i, cache) + 1);
        }

        return cache[n];
    }

    int dp_btmUp(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; (j * j) <= i; ++j) {
                dp[i] = std::min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }

    int numSquares(int n) {
        //vector<int> cache = {0, 1};
        //return dp_topDown(n, cache);

        return dp_btmUp(n);
    }
};
