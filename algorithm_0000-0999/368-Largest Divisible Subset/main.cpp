class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        std::sort(nums.begin(), nums.end());

        // dp[i]: considering nums[0:i], the size of largest subset ending with nums[i]
        int dp[n];
        std::fill(dp, dp + n, 1);
        int prev[n];
        std::fill(prev, prev + n, -1);
        int idx = 0;
        int maxSize = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
                if (dp[i] > maxSize) {
                    maxSize = dp[i];
                    idx = i;
                }
            }
        }

        vector<int> ret;
        while (idx >= 0) {
            ret.push_back(nums[idx]);
            idx = prev[idx];
        }

        return ret;
    }
};
