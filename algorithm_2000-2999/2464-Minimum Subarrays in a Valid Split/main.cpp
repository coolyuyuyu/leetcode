class Solution {
public:
    int validSubarraySplit(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 0);

        int dp[n + 1];
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = INT_MAX / 2;
            for (int j = i; j >= 1; j--) {
                if (std::gcd(nums[j], nums[i]) > 1) {
                    dp[i] = std::min(dp[i], dp[j - 1] + 1);
                }
            }
        }

        return dp[n] < INT_MAX / 2 ? dp[n] : -1;
    }
};
