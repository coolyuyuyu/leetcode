class Solution {
public:
    // 718. Maximum Length of Repeated Subarray
    int findLength(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        s1.insert(s1.begin(), -1);
        s2.insert(s2.begin(), -1);

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
                dp[i][j] = (s1[i] == s2[j] ? (dp[i - 1][j - 1] + 1) : 0);
                ret = std::max(ret, dp[i][j]);
            }
        }

        return ret;
    }

    int minOperations(string initial, string target) {
        int maxLen = findLength(initial, target);
        cout << maxLen << endl;
        return initial.size() - maxLen + target.size() - maxLen;
    }
};
