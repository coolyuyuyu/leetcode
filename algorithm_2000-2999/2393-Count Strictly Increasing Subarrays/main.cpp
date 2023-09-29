class Solution {
public:
    long long countSubarrays(vector<int>& nums) {
        int n = nums.size();

        // dp[i]: the number of strictly increasing subarrays ending at i
        long long dp[n];
        dp[0] = 1;
        for (int i = 1; i < n; ++i) {
            dp[i] = 1;
            if (nums[i - 1] < nums[i]) {
                dp[i] += dp[i - 1];
            }
        }

        long long ret = 0;
        for (int i = 0; i < n; ++i) {
            ret += dp[i];
        }

        return ret;
    }
};
