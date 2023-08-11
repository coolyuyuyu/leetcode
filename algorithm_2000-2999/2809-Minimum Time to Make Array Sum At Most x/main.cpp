class Solution {
public:
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
        int n = nums1.size();

        nums1.insert(nums1.begin(), 0);
        nums2.insert(nums2.begin(), 0);

        vector<int> indexes(n + 1);
        std::iota(indexes.begin() + 1, indexes.end(), 1);
        std::sort(indexes.begin() + 1, indexes.end(), [&](int idx1, int idx2) { return nums2[idx1] < nums2[idx2]; });

        vector<int> presum2(n + 1);
        presum2[0] = nums2[indexes[0]];
        for (int i = 1; i <= n; ++i) {
            presum2[i] = presum2[i - 1] + nums2[indexes[i]];
        }

        // dp[i][j]: sum of nums[1:j] after applying j clearance
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = dp[i - 1][0] + nums1[indexes[i]];
            for (int j = 1; j <= n; ++j) {
                int applyY = dp[i - 1][j - 1] + presum2[i - 1];
                int applyN = dp[i - 1][j] + nums1[indexes[i]] + nums2[indexes[i]] * j;
                dp[i][j] = std::min(applyY, applyN);
            }
        }

        for (int j = 0; j <= n; ++j) {
            if (dp[n][j] <= x) {
                return j;
            }
        }

        return -1;
    }
};
