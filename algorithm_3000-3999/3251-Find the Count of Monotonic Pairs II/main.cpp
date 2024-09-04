class Solution {
public:
    int M = 1e9 + 7;
    int countOfPairs(vector<int>& nums) {
        int n = nums.size();

        // dp[i][j]: the count of monotonic pairs from nums[0:i] and arr1[i] = j

        // arr2[i-1] >= arr2[i]
        // => nums[i-1] - arr1[i-1] >= nums[i] - arr1[i]
        // => arr1[i-1] <= arr1[i] - (nums[i] - nums[i-1])
        // => dp[i][j] = dp[i-1][0] + dp[i-1][1] + ... + dp[i-1][j-(nums[i] - nums[i-1])]
        // => dp[i][j] = dp[i][j-1] + + dp[i-1][nums[i] - nums[i-1]]

        int dp[n][1001];
        for (int j = 0; j <= nums[0]; ++j) {
            dp[0][j] = 1;
        }

        for (int i = 1; i < n; ++i) {
            int d = std::max(0, nums[i] - nums[i - 1]);
            for (int j = 0; j <= nums[i]; ++j) {
                dp[i][j] = (j > 0 ? dp[i][j - 1] : 0) + (j >= d ? dp[i - 1][j - d] : 0);
                dp[i][j] %= M;
            }
        }

        int ret = 0;
        for (int j = 0; j <= nums[n - 1]; ++j) {
            ret += dp[n - 1][j];
            ret %= M;
        }

        return ret;
    }
};
