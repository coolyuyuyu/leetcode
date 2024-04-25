class Solution {
public:
    int byDP(int n) {
        // dp[i][c]: the number of length i strings ending with character c
        int dp[n + 1][5];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j < 5; ++j) {
                dp[i][j] = 0;
            }
        }
        for (int j = 0; j < 5; ++j) {
            dp[1][j] = 1;
        }
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < 5; ++j) {
                for (int k = 0; k <= j; ++k) {
                    dp[i][j] += dp[i - 1][k];
                }
            }
        }

        int ret = 0;
        for (int j = 0; j < 5; ++j) {
            ret += dp[n][j];
        }

        return ret;
    }

    int byMath(int n) {
        // Given n ball, there are n + 1 spaces to insert a bar.
        // And there are 3 other special options: bar0==bar1, bar1==bar2, bar2==bar3
        // => C(n + 1 + 3, 4)

        n += 4;
        int r = 4;

        int ret = 1;
        for (int r = 0; r < 4; ++r) {
            ret *= n - r;
            ret /= r + 1;
        }

        return ret;
    }

    int countVowelStrings(int n) {
        //return byDP(n);
        return byMath(n);
    }
};
