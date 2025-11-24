class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();

        // dp[r] the maximum sum of elements of the array such that dp[r] % 3 == r.
        vector<int> dp(3);
        dp[0] = 0, dp[1] = INT_MIN, dp[2] = INT_MIN;
        for (int i = 0; i < n; ++i) {
            vector<int> tmp = dp;

            int rem = nums[i] % 3;
            dp[(0 + rem) % 3] = std::max(tmp[(0 + rem) % 3], tmp[0] + nums[i]);
            dp[(1 + rem) % 3] = std::max(tmp[(1 + rem) % 3], tmp[1] + nums[i]);
            dp[(2 + rem) % 3] = std::max(tmp[(2 + rem) % 3], tmp[2] + nums[i]);
        }

        return dp[0];
    }
};
