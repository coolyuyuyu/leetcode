class Solution {
public:
    int M = 1e9 + 7;

    int numPermsDISequence(string s) {
        int m = s.size() + 1;
        s = "#" + s;

        // the number of valid length as i+1 permutation with last element as j
        vector<vector<int>> dp(m, vector<int>(m + 1));
        dp[0][0] = 1;
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j <= i; ++j) {
                dp[i][j] = 0;
                if (s[i] == 'I') {
                    for (int k = 0; k < j; ++k) {
                        dp[i][j] += dp[i - 1][k];
                        dp[i][j] %= M;
                    }
                }
                else {
                    for (int k = j; k < i; ++k) {
                        dp[i][j] += dp[i - 1][k];
                        dp[i][j] %= M;
                    }
                }
            }
        }

        int ret = 0;
        for (int j = 0; j <= m; ++j) {
            ret += dp[m - 1][j];
            ret %= M;
        }

        return ret;
    }
};
