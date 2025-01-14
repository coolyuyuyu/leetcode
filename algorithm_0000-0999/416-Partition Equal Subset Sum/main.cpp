class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int total = std::accumulate(nums.begin(), nums.end(), 0);
        if (total & 1) {
            return false;
        }
        int half = total / 2;

        nums.insert(nums.begin(), -1);

        // dp[i][s]: choose some number from nums[1:i], and whose sum equals s
        bool dp[n + 1][half + 1];
        std::memset(dp, 0, sizeof(dp));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int sum = 0; sum <= half; ++sum) {
                dp[i][sum] = dp[i - 1][sum] || (sum >= nums[i] && dp[i - 1][sum - nums[i]]);
            }
        }

        return dp[n][half];
    }
};
