class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int n = nums.size();

        std::sort(nums.begin(), nums.end());

        // dp[i][0]: the longest consecutive subsequence from nums[0:i] ending at nums[i], and nums[i] is not increased
        // dp[i][1]: the longest consecutive subsequence from nums[0:i] ending at nums[i], and nums[i] is increased
        int dp[n][2];
        dp[0][0] = dp[0][1] = 1;

        int ret = std::max(dp[0][0], dp[0][1]);
        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] == nums[i]) {
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = std::max(dp[i - 1][0] + 1, dp[i - 1][1]);
            }
            else if (nums[i - 1] + 1 == nums[i]) {
                dp[i][0] = std::max(dp[i - 1][0] + 1, dp[i - 1][1]);
                dp[i][1] = dp[i - 1][1] + 1;
            }
            else if (nums[i - 1] + 2 == nums[i]) {
                dp[i][0] = dp[i - 1][1] + 1;
                dp[i][1] = 1;
            }
            else {
                dp[i][0] = dp[i][1] = 1;
            }

            ret = std::max({ret, dp[i][0], dp[i][1]});
        }

        return ret;
    }
};
