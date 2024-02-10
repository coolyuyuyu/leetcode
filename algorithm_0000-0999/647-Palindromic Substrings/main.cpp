class Solution {
public:
    // Time: O(n^2), Space: O(n^2)
    int dp1(const string& s) {
        int n = s.size();

        // dp[i][j]: is s[i:j] a palindrome?
        bool dp[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = true;
            }
        }

        int ret = n;
        for (int len = 2; len <= n; ++len) {
            for (int i = 0, j = i + len - 1; j < n; ++i, ++j) {
                if (dp[i][j] = (dp[i + 1][j - 1] && s[i] == s[j])) {
                    ++ret;
                }
            }
        }

        return ret;
    }

    // Time: O(n^2), Space: O(n)
    int dp2(const string& s) {
        int n = s.size();

        bool dp0[n], dp1[n];
        for (int i = 0; i < n; ++i) {
            dp0[i] = dp1[i] = true;
        }

        int ret = n;
        for (int len = 2; len <= n; ++len) {
            for (int i = 0, j = i + len - 1; j < n; ++i, ++j) {
                bool* dp = (len & 1 ? dp1 : dp0);
                if (dp[i] = (dp[i + 1] && s[i] == s[j])) {
                    ++ret;
                }
            }
        }

        return ret;
    }

    // Time: O(n), Space: O(n)
    int manacher(const string& s) {
        string t = "#";
        for (char c : s) {
            t.append(1, c).append("#");
        }

        int n = t.size();

        int ret = 0;
        vector<int> p(n); // p[i]: the longest extended radius of palindromic substring centered at i
        for (int i = 0, maxCtr = -1, maxRht = -1; i < n; ++i) {
            int r = 0;
            if (i < maxRht) {
                int j = maxCtr * 2 - i;
                r = std::min(p[j], maxRht - i);
            }
            while (0 <= (i - r - 1) && (i + r + 1) < n && t[i - r - 1] == t[i + r + 1]) {
                ++r;
            }
            p[i] = r;

            if (maxRht < (i + p[i])) {
                maxCtr = i;
                maxRht = i + p[i];
            }

            if (0 < p[i]) {
                ret += ((p[i] + 1) / 2);
            }
        }

        return ret;
    }

    int countSubstrings(string s) {
        //return dp1(s);
        return dp2(s);

        //return manacher(s);
    }
};
