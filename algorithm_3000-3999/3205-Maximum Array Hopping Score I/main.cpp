class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();

        // dp[i]: the maximum score starting from index 0 and hopping to index i
        int dp[n];
        dp[0] = 0;
        for (int i = 1; i < n; ++i) {
            dp[i] = INT_MIN;
            for (int j = 0; j < i; ++j) {
                dp[i] = std::max(dp[i], dp[j] + (i - j) * nums[i]);
            }
        }

        return dp[n - 1];
    }
};
