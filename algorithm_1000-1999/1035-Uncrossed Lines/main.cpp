class Solution {
public:
    int btmup_dp(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();

        nums1.insert(nums1.begin(), 0);
        nums2.insert(nums2.begin(), 0);

        // dp[i][j]: the maximum number of connecting lines we can draw from nums1[1:i] and nums2[1:j]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][0] = 0;
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = 0;
        }
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (nums1[i] == nums2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }

    int topdn_dp(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();

        nums1.insert(nums1.begin(), 0);
        nums2.insert(nums2.begin(), 0);

        vector<vector<int>> cache(m + 1, vector<int>(n + 1, -1));
        std::function<int(int, int)> f = [&](int i, int j) {
            if (i == 0 || j == 0) {
                return 0;
            }

            int& ret = cache[i][j];
            if (0 <= ret) {
                return ret;
            }

            if (nums1[i] == nums2[j]) {
                ret = f(i - 1, j - 1) + 1;
            }
            else {
                ret = std::max(f(i - 1, j), f(i, j - 1));
            }

            return ret;
        };

        return f(m, n);
    }

    // Same as 1143. Longest Common Subsequence
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        //return btmup_dp(nums1, nums2);
        return topdn_dp(nums1, nums2);
    }
};
