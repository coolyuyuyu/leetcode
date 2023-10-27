class Solution {
public:
    // brute-force, Time: O(n^3)
    string bruteforce(const string& s) {
        auto checkPalimdromic = [&s](size_t pos, size_t len) -> bool {
            if (len == 0) { return true; }
            for (size_t lft = pos, rht = pos + len - 1; lft < rht; ++lft, --rht) {
                if (s[lft] != s[rht]) {
                    return false;
                }
            }

            return true;
        };

        for (size_t len = s.size(); 0 < len; --len) {
            for (size_t pos = 0; (pos + len) < (s.size() + 1); ++pos) {
                if (checkPalimdromic(pos, len)) {
                    return s.substr(pos, len);
                }
            }
        }

        return "";
    }

    // DP, Time: O(n^3), Space: O(n^2)
    string dp1(const string& s) {
        int n = s.size();

        // dp[i][j]: whether s[i:j] is palindromic
        bool dp[n][n];
        for (int i = 0; i + 1 < n; ++i) { // len = 0
            dp[i + 1][i] = true;
        }
        for (int i = 0; i < n; ++i) { // len = 1
            dp[i][i] = true;
        }

        int maxLen = 1, pos = 0;
        for (int len = 2; len <= n; ++len) {
            for (int i = 0, j = i + len - 1; j < n; ++i, ++j) {
                dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
                if (dp[i][j] && maxLen < len) {
                    maxLen = len, pos = i;
                }
            }
        }

        return s.substr(pos, maxLen);
    }

    // DP, Time: O(n^3), Space: O(n)
    string dp2(const string& s) {
        int n = s.size();

        // dpE[i][j]: whether s[i:j] is palindromic and len(s[i:j]) is even
        // dpO[i][j]: whether s[i:j] is palindromic and len(s[i:j]) is odd
        bool dpE[n], dpO[n];
        for (int i = 0; i < n; ++i) {
            dpE[i] = true; // len = 0
            dpO[i] = true; // len = 1
        }

        int maxLen = 1, pos = 0;
        for (int len = 2; len <= n; ++len) {
            bool* dp = ((len & 1) ? dpO : dpE);
            for (int i = 0, j = i + len - 1; j < n; ++i, ++j) {
                dp[i] = dp[i + 1] && s[i] == s[j];
                if (dp[i] && maxLen < len) {
                    maxLen = len, pos = i;
                }
            }
        }

        return s.substr(pos, maxLen);
    }

    // iterative, Time: O(n^3), Space: O(1)
    string iterative(const string& s) {
        size_t ansPos = 0, ansLen = s.empty() ? 0 : 1;
        for (size_t i = 0; (ansLen + 2 * (i + 1)) < (2 * (s.size()) + 1);) {
            size_t lft = i, rht = i;
            while ((rht + 1) < s.size() && s[rht] == s[rht + 1]) {
                ++rht;
            }
            i = rht + 1;

            while (1 <= lft && (rht + 1) < s.size() && s[lft - 1] == s[rht + 1]) {
                --lft, ++rht;
            }

            size_t len = rht - lft + 1;
            if (ansLen < len) {
                ansPos = lft;
                ansLen = len;
            }
        }

        return s.substr(ansPos, ansLen);
    }

    // Manacher, Time: O(n), Space: O(n)
    string manacher(const string& s) {
        string t = "#";
        for (char c : s) {
            t += c;
            t += "#";
        }

        int n = t.size();

        vector<int> p(n, 0); // p[i]: the longest extended radius of palindromic substring centered at i
        int ansPos = 0;
        for (int i = 0, maxCtr = -1, maxRht = -1; i < n; ++i) {
            int r = 0;
            if (i < maxRht) {
                int j = maxCtr * 2 - i;
                r = std::min(p[j], maxRht - i);
            }
            while (0 <= (i - r  - 1) && (i + r + 1) < n && t[i - r - 1] == t[i + r + 1]) {
                ++r;
            }
            p[i] = r;

            if (maxRht < (i + p[i])) {
                maxCtr = i;
                maxRht = i + p[i];
            }

            if (p[ansPos] < p[i]) {
                ansPos = i;
            }
        }

        return s.substr(ansPos/ 2 - p[ansPos] / 2, p[ansPos]);
    }

    string longestPalindrome(string s) {
        //return bruteforce(s);

        //return dp1(s);
        return dp2(s);

        //return iterative(s);

        //return manacher(s);
    }
};
