class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();

        // last[r]: the last index j where nums[j] % k == r
        int last[k];
        std::fill(last, last + k, -1);

        // dp[i][r]: the length of the longest valid subsequence of nums[0:i] and ending at nums[i], where the adjacient sum % k == r
        int dp[n][k];

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int r = 0; r < k; ++r) {
                int t = ((r - nums[i]) % k + k) % k;
                if (last[t] != -1) {
                    int j = last[t];
                    dp[i][r] = dp[j][r] + 1;
                }
                else {
                    dp[i][r] = 1;
                }

                ret = std::max(ret, dp[i][r]);
            }
            last[nums[i] % k] = i;
        }

        return ret;
    }
};
