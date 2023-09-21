class Solution {
public:
    int maxA(int n) {
        // dp[i]: the maximum number of 'A' with at n presses
        int dp[n + 1];
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1] + 1;
            for (int j = 1; j + 1 < i; ++j) {
                dp[i] = std::max(dp[i], dp[j] * (i - j - 1));
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
