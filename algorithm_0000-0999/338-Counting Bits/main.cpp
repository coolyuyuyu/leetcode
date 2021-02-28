class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1);
        for (size_t i = 0; i <= num; ++i) {
            dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp;
    }
};