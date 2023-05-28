class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> dp(n, {1, 1}); // dp[i]: {len of LIS ending at nums[i], the number of LIS ending at nums[i]};

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    if ((dp[j].first + 1) > dp[i].first) {
                        dp[i].first = std::max(dp[i].first, dp[j].first + 1);
                        dp[i].second = dp[j].second;
                    }
                    else if ((dp[j].first + 1) == dp[i].first) {
                        dp[i].second += dp[j].second;
                    }
                }
            }
        }

        int maxLen = 0;
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            if (maxLen < dp[i].first) {
                maxLen = dp[i].first;
                ret = dp[i].second;
            }
            else if (maxLen == dp[i].first) {
                ret += dp[i].second;
            }
        }

        return ret;
    }
};
