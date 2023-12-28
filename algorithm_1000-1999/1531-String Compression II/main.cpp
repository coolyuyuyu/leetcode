class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        if (unordered_set<char>(s.begin(), s.end()).size() == 1) {
            int len = s.size() - k;
            if (len == 0) { return 0; }
            else if (len == 1) { return 1; }
            else if (2 <= len  && len <= 9) { return 2; }
            else if (10 <= len && len <= 99) { return 3; }
            else { assert(len == 100); return 4; }
        }

        int len = s.size();
        s = "#" + s;

        // dp[i][j][c][n]: the minimum length of the run-length encoded version of s[1:i], with j characters removed, and ending with n repeating character c
        // n <= 10 ~ 99 does not increasing extra length. 100 as a special case to be handle in advance
        int dp[len + 1][k + 1][27][11];
        for (int i = 0; i <= len; ++i) {
            for (int j = 0; j <= k; ++j) {
                for (int c = 0; c <= 26; ++c) {
                    for (int n = 0; n <= 10; ++n) {
                        dp[i][j][c][n] = INT_MAX;
                    }
                }
            }
        }
        dp[0][0][26][0] = 0;

        for (int i = 0; i < len; ++i) {
            for (int j = 0; j <= std::min(k, i); ++j) {
                for (int c = 0; c <= 26; ++c) {
                    for (int n = 0; n <= 10; ++n) {
                        if (dp[i][j][c][n] == INT_MAX) { continue; }

                        // delete s[i+1]
                        if (j + 1 <= k) {
                            dp[i + 1][j + 1][c][n] = std::min(dp[i + 1][j + 1][c][n], dp[i][j][c][n]);
                        }

                        // keep s[i+1]
                        if (c == s[i + 1] - 'a') {
                            int add;
                            if (n == 0) { assert(false); }
                            else if (n == 1) { add = 1; }  // a -> a2
                            else if (2 <= n && n <= 8) {add = 0; } // a3->a4
                            else if (n == 9) { add = 1; } // a9->a10;
                            else if (n == 10) { add = 0; } // a10->a11;
                            dp[i +1 ][j][c][min(n + 1, 10)] = min(dp[i + 1][j][c][min(n + 1, 10)], dp[i][j][c][n] + add);
                        }
                        else {
                            dp[i + 1][j][s[i + 1] - 'a'][1] = std::min(dp[i + 1][j][s[i + 1] - 'a'][1], dp[i][j][c][n] + 1);
                        }
                    }
                }
            }
        }

        int ret = INT_MAX;
        for (int c = 0; c <= 26; ++c) {
            for (int n = 0; n <= 10; ++n) {
                ret = std::min(ret, dp[len][k][c][n]);
            }
        }

        return ret;
    }
};

