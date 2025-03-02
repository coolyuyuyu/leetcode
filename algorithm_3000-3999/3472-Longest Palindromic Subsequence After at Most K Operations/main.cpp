class Solution {
public:
    int longestPalindromicSubsequence(string s, int k) {
        int n = s.size();

        // dp[i][j][k]: the length of the longest palindromic subsequence of s[i:j] after performing at most k operations
        int dp[n][n][k + 1];
        for (int a = 0; a < n; ++a) {
            for (int b = 0; b < n; ++b) {
                for (int c = 0; c <= k; ++c) {
                    dp[a][b][c] = -1;
                }
            }
        }

        std::function<int(int, int, int)> f = [&](int i, int j, int k) {
            if (i == j) {
                return 1;
            }
            else if (i > j) {
                return 0;
            }

            int& ret = dp[i][j][k];
            if (ret >= 0) {
                return ret;
            }

            ret = std::max(f(i + 1, j, k), f(i, j - 1, k));

            int cost = std::abs(s[i] - s[j]);
            cost = std::min(cost, 26 - cost);
            if (cost <= k) {
                ret = std::max(ret, 2 + f(i + 1, j - 1, k - cost));
            }

            return ret;
        };

        return f(0, n - 1, k);
    }
};
