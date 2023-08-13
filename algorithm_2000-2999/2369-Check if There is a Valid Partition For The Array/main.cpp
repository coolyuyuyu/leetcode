class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();

        nums.insert(nums.begin(), 0);

        // dp[i]: nums[1:i] is parititiable
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            if (1 <= (i - 1) && dp[i - 2] && nums[i - 1] == nums[i]) {
                dp[i] = true;
                continue;
            }
            if (1 <= (i - 2) && dp[i - 3] && nums[i - 2] == nums[i - 1] && nums[i - 1] == nums[i]) {
                dp[i] = true;
                continue;
            }
            if (1 <= (i - 2) && dp[i - 3] && nums[i-2] + 1 == nums[i - 1] && nums[i-1] + 1 == nums[i]) {
                dp[i] = true;
                continue;
            }
        }

        return dp[n];
    }
};
