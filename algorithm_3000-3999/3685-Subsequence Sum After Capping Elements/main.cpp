class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        int n = nums.size();

        std::sort(nums.begin(), nums.end());

        vector<bool> dp(k + 1, false);
        dp[0] = true;

        vector<bool> ret(n, false);
        for (int x = 1, i = 0; x <= n; ++x) {
            for (; i < n && nums[i] <= x; ++i) {
                for (int s = k; s >= 1 && s >= nums[i]; --s) {
                    dp[s] = dp[s] || dp[s - nums[i]];
                }
            }

            for (int j = 0; j <= n - i && k >= x * j; ++j) {
                if (dp[k - x * j]) {
                    ret[x - 1] = true;
                    break;
                }
            }
        }

        return ret;
    }
};
