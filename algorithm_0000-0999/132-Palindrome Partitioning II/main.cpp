class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        s = "#" + s;

        // dp1[i][j]: is s[i:j] palindrome?
        bool dp1[n + 1][n + 1];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp1[i][j] = true;
            }
        }
        for (int len = 2; len <= n; ++len) {
            for (int i = 1, j = i + len - 1; j <= n; ++i, ++j) {
                dp1[i][j] = dp1[i + 1][j - 1] && s[i] == s[j];
            }
        }

        // dp2[i] : the minimum cuts needed for a palindrome partitioning of s[1:i]
        int dp2[n + 1];
        for (int i = 0; i <= n; ++i) {
            dp2[i] = INT_MAX;
        }
        dp2[0] = -1;
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j >= 1; --j) {
                if (dp1[j][i]) {
                    dp2[i] = std::min(dp2[i], dp2[j - 1] + 1);
                }
            }
        }

        return dp2[n];
    }
};
