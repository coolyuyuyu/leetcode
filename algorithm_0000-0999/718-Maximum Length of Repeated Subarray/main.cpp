class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        // dp[i][j]: the longest common subarray ending at nums1[i] and nums2[j]
        int dp[m + 1][n + 1];
        dp[0][0] = 0;
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = 0;
        }
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = 0;
        }

        int ret = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = (nums1[i] == nums2[j] ? (dp[i - 1][j - 1] + 1) : 0);
                ret = std::max(ret, dp[i][j]);
            }
        }

        return ret;
    }
};
