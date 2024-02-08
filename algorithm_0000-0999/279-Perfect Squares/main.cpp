class Solution {
public:
    int dp_topDown(int n) {
        int cache[n + 1];
        std::fill(cache, cache + n + 1, INT_MAX);
        std::function<int(int)> f = [&](int n) {
            if (n == 0) { return 0; }
            if (cache[n] != INT_MAX) { return cache[n]; }

            int& ret = cache[n];
            for (int i = 1; i * i <= n; ++i) {
                ret = std::min(ret, f(n - i * i) + 1);
            }

            return ret;
        };

        return f(n);
    }

    int dp_btmUp(int n) {
        // dp[i]: the least number of perfect square numbers that sum to i
        int dp[n + 1];
        std::fill(dp, dp + n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                dp[i] = std::min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
    }

    int numSquares(int n) {
        return dp_topDown(n);
        //return dp_btmUp(n);
    }
};
