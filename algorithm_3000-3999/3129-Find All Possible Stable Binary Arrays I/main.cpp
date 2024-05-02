class Solution {
public:
    int M = 1e9 + 7;
    int numberOfStableArrays(int zero, int one, int limit) {
        // dp0[i][j]: the number of stable binary arrays ending with 0 consisting of i zeros and j ones
        int dp0[zero + 1][one + 1];
        // dp1[i][j]: the number of stable binary arrays ending with 1 consisting of i zeros and j ones
        int dp1[zero + 1][one + 1];
        for (int i = 0; i <= zero; ++i) {
            for (int j = 0; j <= one; ++j) {
                dp0[i][j] = 0;
                dp1[i][j] = 0;
            }
        }
        for (int i = 1; i <= zero; ++i) {
            dp0[i][0] = (i <= limit ? 1 : 0);
        }
        for (int j = 1; j <= one; ++j) {
            dp1[0][j] = (j <= limit ? 1 : 0);
        }

        for (int i = 1; i <= zero; ++i) {
            for (int j = 1; j <= one; ++j) {
                for (int k = 1; k <= limit; ++k) {
                    if (i - k >= 0) {
                        dp0[i][j] += dp1[i - k][j];
                        dp0[i][j] %= M;
                    }
                    if (j - k >= 0) {
                        dp1[i][j] += dp0[i][j - k];
                        dp1[i][j] %= M;
                    }
                }
            }
        }

        return (dp0[zero][one] + dp1[zero][one]) % M;
    }
};
