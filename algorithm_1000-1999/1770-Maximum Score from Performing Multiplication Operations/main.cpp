class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size(), m = multipliers.size();

        nums.insert(nums.begin(), 0);
        multipliers.insert(multipliers.begin(), 0);

        // dp[i][j]: the maximum score that taking nums[1:i] and nums[n-j+1:n]
        int dp[m + 1][m + 1];
        dp[0][0] = 0;
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = dp[i - 1][0] + nums[i] * multipliers[i];
        }
        for (int j = 1; j <= m; ++j) {
            dp[0][j] = dp[0][j - 1] + nums[n - j + 1] * multipliers[j];
        }
        for (int len = 1; len <= m; ++len) {
            for (int i = 1, j = len - i; 1 <= j; ++i, --j) {
                dp[i][j] = std::max(dp[i - 1][j] + nums[i] * multipliers[i + j], dp[i][j - 1] + nums[n - j + 1] * multipliers[i + j]);
            }
        }

        int ret = INT_MIN;
        for (int i = 0; i <= m; ++i) {
            ret = std::max(ret, dp[i][m - i]);
        }

        return ret;
    }
};
