class Solution {
public:
    int M = 1e9 + 7;

    int subsequencePairCount(vector<int>& nums) {
        int mxNum = *std::max_element(nums.begin(), nums.end());

        // dp[i][j]: the number of pairs such that gcd of seq1 is i and gcd of seq2 is j
        int dp[mxNum + 1][mxNum + 1];
        std::fill(&dp[0][0], &dp[0][0] + (mxNum + 1) * (mxNum + 1), 0);
        dp[0][0] = 1;
        for (int num : nums) {
            int tmp[mxNum + 1][mxNum + 1];
            std::copy(&dp[0][0], &dp[0][0] + (mxNum + 1) * (mxNum + 1), &tmp[0][0]);
            std::fill(&dp[0][0], &dp[0][0] + (mxNum + 1) * (mxNum + 1), 0);
            for (int i = mxNum; i >= 0; --i) {
                int num1 = std::gcd(i, num);
                for (int j = mxNum; j >= 0; --j) {
                    int num2 = std::gcd(j, num);

                    dp[i][j] += tmp[i][j];
                    dp[i][j] %= M;

                    dp[num1][j] += tmp[i][j];
                    dp[num1][j] %=M;

                    dp[i][num2] += tmp[i][j];
                    dp[i][num2] %= M;
                }
            }
        }

        int ret = 0;
        for (int num = 1; num <= mxNum; ++num) {
            ret += dp[num][num];
            ret %= M;
        }

        return ret;
    }
};
