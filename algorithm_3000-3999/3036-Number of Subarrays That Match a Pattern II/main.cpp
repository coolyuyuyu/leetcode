class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        for (int i = 0; i + 1 < nums.size(); ++i) {
            if (nums[i] < nums[i + 1]) { nums[i] = 1; }
            else if (nums[i] == nums[i + 1]) { nums[i] = 0; }
            else { nums[i] = -1; }
        }
        nums.pop_back();

        int m = nums.size(), n = pattern.size();

        // lps[i]: the maximum value k such that pattern[0:k-1] == pattern[i-k+1:i]
        int lps[n];
        lps[0] = 0;
        for (int i = 1; i < n; ++i) {
            int j = lps[i - 1];
            while (j > 0 && pattern[j] != pattern[i]) {
                j = lps[j - 1];
            }
            lps[i] = j + (pattern[j] == pattern[i] ? 1 : 0);
        }

        int ret = 0;

        // dp[i]: the maximum value k such that nums[i-k+1:i] == pattern[0:k-1]
        int dp[m];
        dp[0] = (nums[0] == pattern[0] ? 1 : 0);
        if (n == 1 && dp[0] == 1) {
            ++ret;
        }
        for (int i = 1; i < m; ++i) {
            int j = dp[i - 1];
            while (j == n || (j > 0 && pattern[j] != nums[i])) {
                j = lps[j - 1];
            }
            dp[i] = j + (pattern[j] == nums[i] ? 1 : 0);

            if (dp[i] == n) {
                ++ret;
            }
        }
        return ret;
    }
};
