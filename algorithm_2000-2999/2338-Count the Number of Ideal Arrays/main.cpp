class Solution {
public:
    long long M = 1e9 + 7;

    vector<int> findPrimes(int n) {
        vector<int> primes;

        bool isPrimes[n + 1];
        std::fill(isPrimes, isPrimes + n + 1, true);
        isPrimes[0] = false;
        if (1 <= n) {
            isPrimes[1] = false;
        }

        for (int i = 2, limit = ceil(sqrt(n)); i <= n; ++i) {
            if (!isPrimes[i]) { continue; }

            primes.push_back(i);

            if (i <= limit) {
                for (int j = i * i; j <= n; j += i) {
                    isPrimes[j] = false;
                }
            }
        }

        return primes;
    }

    int idealArrays(int n, int maxValue) {
        int m = std::log2(maxValue);

        // dp[i][j]: how many different ways to place j same factors into i places.
        long long dp[n + 1][m + 1];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                dp[i][j] = 0;
            }
        }
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                for (int t = 0; t <= j; ++t) {
                    dp[i][j] += dp[i - 1][j - t];
                    dp[i][j] %= M;
                }
            }
        }

        vector<int>primes = findPrimes(maxValue);

        long long ret = 0;
        for (int val = 1; val <= maxValue; ++val) {
            int v = val;
            long long ans = 1;
            for (int prime : primes) {
                int cnt = 0;
                for (; v % prime == 0; v /= prime) {
                    ++cnt;
                }

                ans *= dp[n][cnt];
                ans %= M;
            }

            ret += ans;
            ret %= M;
        }

        return ret;
    }
};
