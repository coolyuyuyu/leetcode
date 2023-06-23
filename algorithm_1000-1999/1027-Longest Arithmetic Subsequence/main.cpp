class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int offset = 500;

        // dp[i][j]: the length of longest arithematic sequence with common difference as j and ending at nums[i]
        vector<vector<int>> dp(n, vector<int>(1001, 1));

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int diff = nums[i] - nums[j];
                dp[i][diff + offset] = dp[j][diff + offset] + 1;
                ret = std::max(ret, dp[i][diff + offset]);
            }
        }

        return ret;
    }
};
