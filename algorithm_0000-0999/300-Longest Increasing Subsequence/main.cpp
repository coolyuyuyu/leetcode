class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        // dp[i]: the length of the longest strictly increasing subsequence(0,i-1) and nums[i]
        vector<int> dp(n);

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }

            ret = std::max(ret, dp[i]);
        }

        return ret;
    }
};
