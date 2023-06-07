class Solution {
public:
    // Time: O(mn)
    string dynamicPrograming(string s1, string s2) {
        int m = s1.size(), n = s2.size();

        s1 = "#" + s1;
        s2 = "#" + s2;

        // dp[i][j]: the length of shortest substring of s1[1:i] K such that s2[1:j] is a subsequence of s1[i-K+1:i]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][0] = 0;
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = 0;
        }
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = INT_MAX / 2;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = dp[i - 1][j] + 1;
                }
            }
        }

        int minLen = INT_MAX / 2;
        int pos = -1;
        for (int i = n; i <= m; ++i) {
            if (dp[i][n] < minLen) {
                minLen = dp[i][n];
                pos = i - minLen + 1;
            }
        }

        return 0 <= pos ? s1.substr(pos, minLen) : "";
    }

    // Time: O(kn), where k is the number of character in s1 equals to s2[0]
    string greedy(string s1, string s2) {
        int m = s1.size(), n = s2.size();

        s1 = "#" + s1;

        vector<std::array<int, 26>> next(m + 1);
        next[m].fill(-1);
        for (int i = m; 0 < i--;) {
            std::copy(next[i + 1].begin(), next[i + 1].end(), next[i].begin());
            next[i][s1[i + 1] - 'a'] = i + 1;
        }

        int pos, minLen = INT_MAX;
        for (int i = 1; i <= m; ++i) {
            if (s1[i] != s2[0]) {
                continue;
            }

            int j = i - 1;
            for (char c : s2) {
                j = next[j][c - 'a'];
                if (j < 0) {
                    break;
                }
            }
            if (0 < j) {
                int len = j - i + 1;
                if (len < minLen) {
                    minLen = len;
                    pos = i;
                }
            }
        }

        return minLen < INT_MAX ? s1.substr(pos, minLen) : "";
    }

    string minWindow(string s1, string s2) {
        //return dynamicPrograming(s1, s2);
        return greedy(s1, s2);
    }
};
