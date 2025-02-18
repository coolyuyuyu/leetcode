class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size(), n = strs.empty() ? 0 : strs[0].size();

        std::function<bool(int, int)> checkColLE = [&](int c1, int c2) {
            for (int r = 0; r < m; ++r) {
                if (strs[r][c1] < strs[r][c2]) {
                    return false;
                }
            }

            return true;
        };

        // dp[i]: the longest increasing subsequence from columns[0:i] ending at i column
        int dp[n];
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (checkColLE(i, j)) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }

        int lis = 0;
        for (int i = 0; i < n; ++i) {
            lis = std::max(lis, dp[i]);
        }

        return n - lis;
    }
};
