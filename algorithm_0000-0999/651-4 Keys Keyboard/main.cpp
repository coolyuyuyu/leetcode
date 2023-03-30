class Solution {
public:
    int maxA(int n) {
        vector<int> dp(n + 1); // dp[i]: the maximum number of 'A' of i presses
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1] + 1;
            for (int j = 1; j < (i - 2); ++j) {
                dp[i] = std::max(dp[i], dp[i - j - 2] * (j + 1));
            }
        }

        return dp[n];
    }
};

// A C V
//     i
// A C V V
//       i
// A C V V V
//         i
