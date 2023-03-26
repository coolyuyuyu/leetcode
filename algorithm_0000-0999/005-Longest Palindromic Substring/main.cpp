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
        size_t ansPos = 0, ansLen = s.empty() ? 0 : 1;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), true));
        for (size_t len = 2; len <= s.size(); ++len) {
            for (size_t i = 0; (i + len) < (s.size() + 1); ++i) {
                size_t j = i + len - 1;
                dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
                if (dp[i][j] && ansLen < len) {
                    ansPos = i, ansLen = len;
                }
            }
        }

        return s.substr(ansPos, ansLen);
    }

    // DP, Time: O(n^3), Space: O(n)
    string dp2(const string& s) {
        size_t ansPos = 0, ansLen = s.empty() ? 0 : 1;
        vector<bool> dp0(s.size(), true);
        vector<bool> dp1(s.size(), true);
        for (size_t len = 2; len <= s.size(); ++len) {
            for (size_t i = 0; (i + len) < (s.size() + 1); ++i) {
                size_t j = i + len - 1;
                auto& dp = (len % 2 ? dp1 : dp0);
                dp[i] = s[i] == s[j] && dp[i + 1];
                if (dp[i] && ansLen < len) {
                    ansPos = i, ansLen = len;
                }
            }
        }

        return s.substr(ansPos, ansLen);
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
            t += '#';
        }

        size_t n = t.size();
        vector<int> p(n, 0); // p[i]: radius of the longest palindromic substring cenceted at i
        for (int i = 0, maxCtr = -1, maxRht = -1; i < t.size(); ++i) {
            int r = 0;
            if (i <= maxRht) {
                int j = 2 * maxCtr - i;
                r = std::min(p[j], maxRht - i);
            }
            while (0 <= (i - r - 1) && (i + r + 1) < n && t[i - r - 1] == t[i + r + 1]) {
                ++r;
            }

            p[i] = r;
            if (maxRht < i + r) {
                maxCtr = i;
                maxRht = i + r;
            }
        }

        int ansPos, ansRadius = -1;
        for (int i = 0; i < n; ++i) {
            if (ansRadius < p[i]) {
                ansPos = i;
                ansRadius = p[i];
            }
        }

        return s.substr(ansPos / 2 - ansRadius / 2, ansRadius);
    }

    string longestPalindrome(string s) {
        //return bruteforce(s);

        //return dp1(s);
        //return dp2(s);

        //return iterative(s);

        return manacher(s);
    }
};
