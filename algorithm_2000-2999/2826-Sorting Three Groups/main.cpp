class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();

        nums.insert(nums.begin(), 0);

        // dp[i][j]: the minimum number of operations to make nums[1:i] beautiful and nums[i] == j
        int dp[nums.size() + 1][4];
        dp[0][1] = dp[0][2] = dp[0][3] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i][1] = dp[i - 1][1] + (nums[i] != 1 ? 1 : 0);
            dp[i][2] = std::min({dp[i - 1][1], dp[i - 1][2]}) + (nums[i] != 2 ? 1 : 0);
            dp[i][3] = std::min({dp[i - 1][1], dp[i - 1][2], dp[i - 1][3]}) + (nums[i] != 3 ? 1 : 0);
        }

        return std::min({dp[n][1], dp[n][2], dp[n][3]});
    }
};
