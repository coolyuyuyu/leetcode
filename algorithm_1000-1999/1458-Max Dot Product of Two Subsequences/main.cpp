class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();

        nums1.insert(nums1.begin(), 0);
        nums2.insert(nums2.begin(), 0);

        // dp[i][j]: the maximum dot product between non-empty subsequences of nums1 and nums2
        int dp[m + 1][n + 1];

        dp[0][0] = INT_MIN / 2;
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = INT_MIN / 2;
        }
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = INT_MIN / 2;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int a = std::max(0, dp[i - 1][j - 1]) + nums1[i] * nums2[j]; // pair nums1[i] and nums2[j]
                int b = std::max(dp[i - 1][j], dp[i][j - 1]); // do not pair nums1[i] and nums2[j]
                dp[i][j] = std::max(a, b);
            }
        }

        return dp[m][n];
    }
};
