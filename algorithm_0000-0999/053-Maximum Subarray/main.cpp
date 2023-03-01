class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // dp[i] maximum subarray ending at nums[i]

        int ret = nums[0];
        int dp = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp = std::max(dp + nums[i], nums[i]);
            ret = std::max(ret, dp);
        }

        return ret;
    }
};
