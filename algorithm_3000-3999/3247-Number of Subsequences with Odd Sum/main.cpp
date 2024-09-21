class Solution {
public:
    int M = 1e9 + 7;
    int subsequenceCount(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 0);

        // dp[i][0]: the number of subsequences with an even sum of elements from nums[1:i]
        // dp[i][1]: the number of subsequences with an odd sum of elements from nums[1:i]
        int dp[n + 1][2];
        dp[0][0] = 1;
        dp[0][1] = 0;
        for (int i = 1; i <= n; ++i) {
            if (nums[i] % 2) {
                dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
                dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
            }
            else {
                dp[i][0] = dp[i - 1][0] * 2;
                dp[i][1] = dp[i - 1][1] * 2;;
            }
            dp[i][0] %= M;
            dp[i][1] %= M;
        }

        return dp[n][1];
    }
};
