class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // dp[i]: the maximum sum of subarray ending at nums[i]
        int dp = nums[0];
        int ret = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            dp = std::max(dp + nums[i], nums[i]);
            ret = std::max(ret, dp);
        }

        return ret;
    }
};
