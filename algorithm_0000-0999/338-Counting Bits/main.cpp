class Solution {
public:
    vector<int> countBits(int n) {
        // 0:  0
        // 1:  1
        // 2:  10
        // 3:  11
        // 4:  100
        // 5:  101
        // 6:  110
        // 7:  111

        // dp[i]: the number of 1's in the binary representation of i
        vector<int> dp(n + 1);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i >> 1] + (i & 1);
        }

        return dp;
    }
};
