class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();

        nums.insert(nums.begin(), 0);

        // dp[i][r]: the length of the longest valid subsequence of nums[1:i] and ending at nums[i], where the adjacient sum % k == r
        int dp[n + 1][k];
        for (int r = 0; r < k; ++r) {
            dp[0][r] = 0;
        }

        // last[r]: the last index j where nums[j] % k == r
        int last[k];
        std::fill(last, last + k, 0);

        int ret = 0;
        for (int i = 1; i <= n; ++i) {
            for (int r = 0; r < k; ++r) {
                int j = ((r - nums[i]) % k + k) % k;
                dp[i][r] = dp[last[j]][r] + 1;

                ret = std::max(ret, dp[i][r]);
            }
            last[nums[i] % k] = i;
        }

        return ret;
    }

    int maximumLength(vector<int>& nums) {
        return maximumLength(nums, 2);
    }
};
