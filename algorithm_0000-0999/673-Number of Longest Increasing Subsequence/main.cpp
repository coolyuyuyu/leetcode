class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        // dp[i]: {the length of LIS ending at nums[i], the number of LIS ending at nums[i]}
        vector<pair<int, int>> dp(n, {1, 1});

        int lenLIS = 0, cntLIS = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    if ((dp[j].first + 1) > dp[i].first) {
                        dp[i].first = dp[j].first + 1;
                        dp[i].second = dp[j].second;
                    }
                    else if ((dp[j].first + 1) == dp[i].first) {
                        dp[i].second += dp[j].second;
                    }
                }
            }

            if (lenLIS < dp[i].first) {
                lenLIS = dp[i].first;
                cntLIS = dp[i].second;
            }
            else if (lenLIS == dp[i].first) {
                cntLIS += dp[i].second;
            }
        }

        return cntLIS;
    }
};
