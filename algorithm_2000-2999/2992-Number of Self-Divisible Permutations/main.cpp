class Solution {
public:
    int selfDivisiblePermutationCount(int n) {
        // state: the binary representation of used numbers
        // dp[i][state]: the number of self-divisible permutations of state
        int dp[n + 1][1 << n];
        for (int i = 0; i <= n; ++i) {
            for (int state = 0; state < (1 << n); ++state) {
                dp[i][state] = 0;
            }
        }
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int state = 0; state < (1 << n); ++state) {
                for (int num = 1; num <= n; ++num) {
                    if (gcd(num, i) != 1) { continue; }
                    if ((state & (1 << (num - 1))) == 0) { continue; }
                    dp[i][state] += dp[i - 1][state - (1 << (num - 1))];
                }
            }
        }

        return dp[n][(1 << n) - 1];
    }
};
