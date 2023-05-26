class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<int> dp(n, 1); // dp[i]: considering nums[0:i], the size of largest divisible subset containing nums[i]
        vector<int> prev(n, -1);
        int maxSize = 0, idx = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if ((nums[i] % nums[j]) == 0) {
                    if (dp[i] < (dp[j] + 1)) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }

            if (maxSize < dp[i]) {
                maxSize = dp[i];
                idx = i;
            }
        }

        vector<int> ret;
        while (0 <= idx) {
            ret.push_back(nums[idx]);
            idx = prev[idx];
        }
        return ret;
    }
};
