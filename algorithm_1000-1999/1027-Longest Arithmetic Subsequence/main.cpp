class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();

        //dp[i][j]: the length of the longest arithmetic subsequence with difference as j ending at nums[i]
        vector<vector<int>> dp(n, vector<int>(1001, 1));

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int diff = nums[i] - nums[j];
                dp[i][diff + 500] = dp[j][diff + 500] + 1;
                ret = std::max(ret, dp[i][diff + 500]);
            }
        }

        return ret;
    }
};
