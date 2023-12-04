class Solution {
public:
    // Time: O(n^2), Space: O(n)
    int dp(const vector<int>& nums) {
        int n = nums.size();

        // dp[i]: the length of the longest strictly increasing subsequence from nums[0:i] and ending at nums[i]
        int dp[n];
        std::fill(dp, dp + n, 1);

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }

            ret = std::max(ret, dp[i]);
        }

        return ret;
    }

    // Time: O(nlogn), Space: O(n)
    int greedy(const vector<int>& nums) {
        vector<int> lis;
        for (int num : nums) {
            if (lis.empty() || lis.back() < num) {
                lis.push_back(num);
            }
            else {
                auto itr = std::lower_bound(lis.begin(), lis.end(), num);
                *itr = num;
            }
        }

        return lis.size();
    }

    int lengthOfLIS(vector<int>& nums) {
        //return dp(nums);
        return greedy(nums);
    }
};
