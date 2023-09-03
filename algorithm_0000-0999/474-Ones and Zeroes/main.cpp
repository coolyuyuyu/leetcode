class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // dp[i][j]:  the size of the largest subset such that there are at most i 0's and j 1's
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (const string& str : strs) {
            int cnt0 = 0, cnt1 = 0;
            for (char c : str) {
                ++(c == '0' ? cnt0 : cnt1);
            }

            auto tmp = dp;
            for (int i = cnt0; i <= m; ++i) {
                for (int j = cnt1; j <= n; ++j) {
                    dp[i][j] = std::max(dp[i][j], tmp[i - cnt0][j - cnt1] + 1);
                }
            }
        }

        return dp[m][n];
    }
};
