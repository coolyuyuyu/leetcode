class Solution {
public:
    vector<int> computeLPS(const string& s) {
        if (s.empty()) {
            return {};
        }

        int n = s.size();
        vector<int> dp(n);
        dp[0] = 0;
        for (int i = 1; i < n; ++i) {
            int j = dp[i - 1];
            while (0 < j && s[j] != s[i]) {
                j = dp[j - 1];
            }
            dp[i] = j + (s[j] == s[i] ? 1 : 0);
        }

        return dp;
    }

    int transfer(int matchedLen, char c, const string& t, const vector<int>& lcp) {
        int j = matchedLen;
        while (0 < j && t[j] != c) {
            j = lcp[j - 1];
        }
        matchedLen = j + (t[j] == c ? 1 : 0);

        return matchedLen;
    }

    int M = 1e9 + 7;
    void accumulate(int& a, int b) {
        a = (a + b) % M;
        if (a < 0)  {
            a = (a + M) % M;
        }
    }

    int dp[501][50][2] = {0};
    int countGoodStrings(const string& s, const string& evil, const vector<int>& lcp) {
        int n = s.size();
        int m = evil.size();
        
        memset(dp, 0, sizeof(dp));
        dp[0][0][1] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i < j) {
                    continue;
                }
                for (char c = 'a'; c <= 'z'; ++c) {
                    int preLen = transfer(j, c, evil, lcp);
                    if (m <= preLen) {
                        continue;
                    }
                    if (c < s[i]) {
                        accumulate(dp[i + 1][preLen][0], dp[i][j][1]);
                    }
                    else if (c == s[i]) {
                        accumulate(dp[i + 1][preLen][1], dp[i][j][1]);
                    }
                    accumulate(dp[i + 1][preLen][0], dp[i][j][0]);
                }
            }
        }

        int ans = 0;
        for (int j = 0; j < m; ++j) {
            accumulate(ans, dp[n][j][0]);
            accumulate(ans, dp[n][j][1]);
        }
        return ans;
    }

    int findGoodStrings(int n, string s1, string s2, string evil) {
        vector<int> lcp = computeLPS(evil);

        int ret = countGoodStrings(s2, evil, lcp);
        if (std::any_of(s1.begin(), s1.end(), [](char c) { return c != 'a'; })) {
            string tmp = s1;
            for (int i = tmp.size(); 0 < i--;) {
                if (tmp[i] > 'a') {
                    tmp[i]--;
                    break;
                }
                else {
                    tmp[i] = 'z';
                }
            }

            accumulate(ret, -countGoodStrings(tmp, evil, lcp));
        }

        return ret;
    }
};

// DIGIT DP
//
// dp[i][j][eq] for length N and string S and evil:
// => the number of good strings such that each good string T of length i and T[i-j+1:i] == evil[0:j-1] and eq(T[0:i-1], S[0:i-1])
//
// KMP to tranfer dp state
