class Solution {
public:
    int minimumOperations(string num) {
        int n = num.size();
        num = "#" + num;

        // dp[i][j]: the minimum number of operations required to make num[1:i] % 25 == j
        int dp[n + 1][25];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j < 25; ++j) {
                dp[i][j] = INT_MAX / 2;
            }
        }
        dp[0][0] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 25; ++j) {
                // delete
                dp[i][j] = std::min(dp[i][j], dp[i - 1][j] + 1);

                // not delete;
                int r = (j * 10 + num[i] - '0') % 25;
                dp[i][r] = std::min(dp[i][r], dp[i - 1][j]);
            }
        }

        return dp[n][0];
    }
};
