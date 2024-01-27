class Solution {
public:
    int M = 1e9 + 7;

    // Time: O(n * n * k)
    int dp1(int n, int k) {
        // [X X X X X] 6
        // 1. [6 X X X X X]
        // 2. [X 6 X X X X]
        // 3. [X X 6 X X X]
        // 4. [X X X 6 X X]
        // 5. [X X X X 6 X]
        // 6. [X X X X X 6]
        // dp[6][j] = dp[5][j - 5] + dp[5][j - 4] + dp[5][j - 3] + dp[5][j - 2] + dp[5][j - 1] + dp[5][j - 0]

        // => dp[i][j] = dp[i-1][j - (i-1)] + dp[i-1][j-(i-2)] + ... + dp[i-1][j-(0)]

        // dp[i][j]: the number of different permutations from numbers 1 to n such that there are exactly k inverse pairs
        int dp[n + 1][k + 1];
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 1;
        }
        for (int i = 0; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                dp[i][j] = 0;
            }
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                dp[i][j] = 0;
                for (int x = 0; x <= std::min(i - 1, j); ++x) {
                    dp[i][j] += dp[i - 1][j - x];
                    dp[i][j] %= M;
                }
            }
        }

        return dp[n][k];
    }

    // Time: O(n * k)
    int dp2(int n, int k) {
        // => A: dp[i][j] = dp[i-1][j-0] + dp[i-1][j-1] + ... + dp[i-1][j-(i-1)]
        // => B: dp[i][j-1] = dp[i-1][j-1] + dp[i-1][j-2] + ... + dp[i-1][j-(i)]

        // => A - B: dp[i][j] - dp[i][j-1] = dp[i-1][j-0] - dp[i-1][j-(i)]
        // => dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-i]

        int dp[n + 1][k + 1];
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 1;
        }
        for (int i = 0; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                dp[i][j] = 0;
            }
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                dp[i][j] %= M;
                if (j >= i) {
                    dp[i][j] -= dp[i - 1][j - i];
                    dp[i][j] = (dp[i][j] + M) % M;
                }
            }
        }

        return dp[n][k];
    }

    int kInversePairs(int n, int k) {
        //return dp1(n, k);
        return dp2(n, k);
    }
};
