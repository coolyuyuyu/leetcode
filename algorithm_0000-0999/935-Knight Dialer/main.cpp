class Solution {
public:
    int M = 1e9 + 7;
    
    int knightDialer(int n) {
        if (n == 1) { return 10; }

        // dp[i][10]: how many distinct phone numbers of length i
        int dp[10];
        std::fill(dp, dp + 10, 1);
        dp[5] = 0;

        for (int i = 2; i <= n; ++i) {
            int tmp[10];
            std::copy(dp, dp + 10, tmp);

            dp[0] = (tmp[4] + tmp[6]) % M;
            dp[1] = (tmp[6] + tmp[8]) % M;
            dp[2] = (tmp[7] + tmp[9]) % M;
            dp[3] = (tmp[4] + tmp[8]) % M;
            dp[4] = ((tmp[0] + tmp[3]) % M + tmp[9])% M;
            dp[6] = ((tmp[0] + tmp[1]) % M + tmp[7])% M;
            dp[7] = (tmp[2] + tmp[6]) % M;
            dp[8] = (tmp[1] + tmp[3]) % M;
            dp[9] = (tmp[2] + tmp[4]) % M;
        }

        int ret = 0;
        for (int i = 0; i < 10; ++i) {
            ret = (ret + dp[i]) % M;
        }

        return ret;
    }
};
