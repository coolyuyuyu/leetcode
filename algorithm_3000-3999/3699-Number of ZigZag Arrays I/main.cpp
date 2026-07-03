class Solution {
public:
    int M = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1; // each elements lies in range [0, m-1]

        // dp0[i][j]: the total number of length i+1 ZigZag arrays, where last element is j, and the last 2 elements are decreasing
        int dp0[n][m];
        for (int j = 0; j < m; ++j) { dp0[0][j] = 1; }

        // dp1[i][j]: the total number of length i+1 ZigZag arrays, where last element is j, and the last 2 elements are increasing
        int dp1[n][m];
        for (int j = 0; j < m; ++j) { dp1[0][j] = 1; }

        for (int i = 1; i < n; ++i) {
            int sum0[m], sum1[m];
            std::partial_sum(&dp0[i - 1][0], &dp0[i - 1][0] + m, sum0, [&](int a, int b) { return (a + b) % M; });
            std::partial_sum(&dp1[i - 1][0], &dp1[i - 1][0] + m, sum1, [&](int a, int b) { return (a + b) % M; });
            for (int j = 0; j < m; ++j) {
                dp0[i][j] = (sum1[m - 1] - sum1[j] + M) % M;
                dp1[i][j] = (j > 0 ? sum0[j - 1] : 0);
            }
        }

        int ret = 0;
        for (int j = 0; j < m; ++j) {
            ret += dp0[n - 1][j];
            ret %= M;
            ret += dp1[n - 1][j];
            ret %= M;
        }

        return ret;
    }
};
