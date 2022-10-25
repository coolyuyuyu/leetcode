class Solution {
public:
    int dp(vector<int>& nums) {
        int len = 1;

        vector<int> dp(nums.size(), 1);
        for (size_t i = 1; i < nums.size(); ++i) {
            for (size_t j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
            len = std::max(len, dp[i]);
        }

        return len;
    }

    int lengthOfLIS(vector<int>& nums) {
        return dp(nums);
    }
};
