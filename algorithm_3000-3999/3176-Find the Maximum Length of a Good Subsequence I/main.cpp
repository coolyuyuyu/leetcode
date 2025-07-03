class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();

        // dp[i][t]: the maximum possible length of a good subsequence of nums[1:i] and there are t times of indices such that seq[i] != seq[i + 1]
        int dp[n][k + 1];

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int t = 0; t <= k; ++t) {
                int ans = 1;
                for (int j = 0; j < i; ++j) {
                    if (nums[j] == nums[i]) {
                        ans = std::max(ans, dp[j][t] + 1);
                    }
                    else if (t >= 1){
                        ans = std::max(ans, dp[j][t - 1] + 1);
                    }
                }
                dp[i][t] = ans;
                ret = std::max(ret, ans);
            }
        }

        return ret;
    }
};
