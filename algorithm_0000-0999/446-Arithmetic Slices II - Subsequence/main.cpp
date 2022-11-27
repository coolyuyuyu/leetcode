class Solution {
public:
    // Time: O(n^2), Space: O(n^2)
    int numberOfArithmeticSlices(vector<int>& nums) {
        size_t n = nums.size();
        vector<map<long, int>> dp(n);
        int ans = 0;
        for (size_t i = 1; i < n; ++i) {
            for (size_t j = 0; j < i; ++j) {
                long diff = (long)nums[i] - nums[j];
                auto itr = dp[j].find(diff);
                int cnt = (itr == dp[j].end()) ? 0 : itr->second;
                dp[i][diff] += (dp[j][diff] + 1);

                ans += cnt;
            }
        }

        return ans;
    }
};
