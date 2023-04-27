class Solution {
public:
    // Time: O(mn)
    string dynamicPrograming(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        s1.insert(s1.begin(), '#');
        s2.insert(s2.begin(), '#');

        // dp[i][j]: the length of minimum substring of s1[1:i] k such that s2[1:j] is a subsequence of s1[i-k+1:i]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX / 2));
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

        int pos = -1, len = INT_MAX / 2;
        for (int i = 1; i <= m; ++i) {
            if (dp[i][n] < len) {
                len = dp[i][n];
                pos = i - len + 1;
            }
        }

        return pos != -1 ? s1.substr(pos, len) : "";
    }

    // Time: O(kn), where k is the number of character in s1 equals to s2[0]
    string greedy(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        s1.insert(s1.begin(), '#');

        // next[i][c]: look right from index i, the nearest index of character c
        vector<array<int, 26>> next(m + 1);
        next[m].fill(-1);
        for (int i = m; 0 < i--;) {
            std::copy(next[i + 1].begin(), next[i + 1].end(), next[i].begin());
            next[i][s1[i + 1] - 'a'] = i + 1;
        }

        int pos = -1, len = INT_MAX;
        for (int i = 1; i <= m; ++i) {
            if (s1[i] != s2[0]) {
                continue;
            }

            int j = i - 1;
            for (char c : s2) {
                j = next[j][c - 'a'];
                if (j == -1) {
                    break;
                }
            }

            if (0 <= j && (j - i + 1) < len) {
                pos = i;
                len = j - i + 1;
            }
        }

        return len < INT_MAX ? s1.substr(pos, len) : "";
    }

    string minWindow(string s1, string s2) {
        //return dynamicPrograming(s1, s2);
        return greedy(s1, s2);
    }
};
