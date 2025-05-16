class Solution {
public:
    int M = 1e9 + 7;

    int quickPow(int base, int exp) {
        int ret = 1;
        for (; exp; exp >>= 1) {
            if (exp & 1) {
                ret = 1L * ret * base % M;
            }
            base = 1L * base * base % M;
        }

        return ret;
    };

    int countBalancedPermutations(string num) {
        int sum = 0;
        for (char c : num) {
            int d = c - '0';
            sum += d;
        }
        if (sum & 1) {
            return 0;
        }

        int n = num.size();
        int halfSum = sum / 2;
        int halfLen = n / 2;

        vector<int> digits(10, 0);

        // dp[i][s]: the number of ways to pick i digits and its sum == s
        int dp[halfLen + 1][halfSum + 1];
        for (int i = 0; i <= halfLen; ++i) {
            for (int s = 0; s <= halfSum; ++s) {
                dp[i][s] = 0;
            }
        }
        dp[0][0] = 1;
        for (char c : num) {
            int d = c - '0';
            ++digits[d];
            for (int i = halfLen; i >= 1; --i) {
                for (int s = halfSum; s >= d; --s) {
                    dp[i][s] += dp[i - 1][s - d];
                    dp[i][s] %= M;
                }
            }
        }

        int factorial[n + 1];
        factorial[0] = 1;
        for (int i = 1; i <= n; ++i) {
            factorial[i] = 1LL * factorial[i - 1] * i % M;
        }

        int invFactorial[n + 1];
        for (int i = 0; i <= n; ++i) {
            invFactorial[i] = quickPow(factorial[i], M - 2);
        }

        int ret = dp[halfLen][halfSum];
        ret = 1L * ret * factorial[halfLen] % M;
        ret = 1L * ret * factorial[n - halfLen] % M;
        for (int cnt : digits) {
            ret = 1L * ret * invFactorial[cnt] % M;
        }

        return ret;
    }
};
