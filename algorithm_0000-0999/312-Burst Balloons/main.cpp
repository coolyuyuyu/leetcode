class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        // dp[i][j]: the maximum coins you can collect by bursting the balloons[i:j]
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int len = 1; len <= n; ++len) {
            for (int i = 1, j = i + len - 1; j <= n; ++i, ++j) {
                for (int k = i; k <= j; ++k) {
                    // nums[k] is the last one to burst in nums[i:j]
                    dp[i][j] = std::max(dp[i][j], dp[i][k - 1] + nums[i - 1] * nums[k] * nums[j + 1] + dp[k + 1][j]);
                }
            }
        }

        return dp[1][n];
    }
};
