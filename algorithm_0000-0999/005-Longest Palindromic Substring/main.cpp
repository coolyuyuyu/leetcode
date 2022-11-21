class Solution {
public:
    // brute-force, Time: O(n^3)
    string bruteforce(const string& s) {
        auto checkPalindrome = [&s](size_t pos, size_t len) -> bool {
            for (size_t lft = pos, rht = pos + len; (lft + 1) < rht--; ++lft) {
                if (s[lft] != s[rht]) {
                    return false;
                }
            }
            return true;
        };

        for (size_t l = s.size(); 0 < l; --l) {
        for (size_t len = s.size(); 0 < len; --len) {
                if (checkPalindrome(pos, len)) {
                    return s.substr(pos, len);
                }
            }
        }

        return "";
    }

    // DP, Time: O(n^3), Space: O(n^2)
    string dp1(const string& s) {
        size_t ansPos = 0, ansLen = s.empty() ? 0 : 1;

        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), true)); // dp[i][j]: s[i:j+1] is palindromic or not
        for (size_t len = 2; len <= s.size(); ++len) {
            for (size_t pos = 0; (pos + len) <= s.size(); ++pos) {
                dp[pos][pos + len - 1] = s[pos] == s[pos + len - 1] && dp[pos + 1][pos + len - 2];
                if (dp[pos][pos + len - 1] && ansLen < len) {
                    ansPos = pos;
                    ansLen = len;
                }
            }
        }

        return s.substr(ansPos, ansLen);
    }

    // DP, Time: O(n^3), Space: O(n)
    string dp2(const string& s) {
        size_t ansPos = 0, ansLen = s.empty() ? 0 : 1;

        vector<bool> dp0(s.size(), true), dp1(s.size(), true);
        for (size_t len = 2; len <= s.size(); ++len) {
            for (size_t pos = 0; (pos + len) <= s.size(); ++pos) {
                vector<bool>& dp = (len % 2) ? dp0 : dp1;
                dp[pos] = dp[pos + 1] && s[pos] == s[pos + len - 1];
                if (dp[pos] && ansLen < len) {
                    ansPos = pos;
                    ansLen = len;
                }
            }
        }

        return s.substr(ansPos, ansLen);
    }

    // iterative, Time: O(n^3), Space: O(1)
    string iterative(const string& s) {
        size_t ansPos = 0, ansLen = s.empty() ? 0 : 1;

        for (size_t i = 0; i < s.size() && (ansLen + 1) < ((s.size() - i) * 2);) {
            size_t lft = i, rht = i;
            while ((rht + 1) < s.size() && s[rht] == s[rht + 1]) {
                ++rht;
            }
            i = rht + 1;

            while (0 < lft && (rht + 1) < s.size() && s[lft - 1] == s[rht + 1]) {
                --lft, ++rht;
            }

            int len = rht - lft + 1;
            if (ansLen < len) {
                ansPos = lft;
                ansLen = len;
            }
        }

        return s.substr(ansPos, ansLen);
    }

    string longestPalindrome(string s) {
        //return bruteforce(s);
        //return dp1(s);
        //return dp2(s);

        return iterative(s);
    }
};
