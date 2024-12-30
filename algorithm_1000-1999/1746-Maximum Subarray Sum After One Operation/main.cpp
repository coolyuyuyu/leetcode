class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        // dp1[i]: the maximum subarray sum ending at nums[i]
        // dp2[i]: the maximum subarray sum ending at nums[i] with one operation on the subarray
        int dp1 = nums[0], dp2 = nums[0] * nums[0];
        int ret = std::max(dp1, dp2);
        for (int i = 1; i < nums.size(); ++i) {
            int tmp1 = dp1, tmp2 = dp2;
            dp1 = std::max({tmp1 + nums[i], nums[i]});
            dp2 = std::max({tmp1 + nums[i] * nums[i], nums[i] * nums[i], tmp2 + nums[i]});
            ret = std::max({ret, dp1, dp2});
        }

        return ret;
    }
};
