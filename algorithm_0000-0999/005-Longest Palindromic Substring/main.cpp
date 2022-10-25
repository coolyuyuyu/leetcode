class Solution {
public:
    // brute-force, Time: O(n^3)
    string bruteforce(const string& s) {
        auto checkPalindrome = [&](size_t pos, size_t len) {
            for (size_t lft = pos, rht = pos + len - 1; lft < rht; ++lft, --rht) {
                if (s[lft] != s[rht]) {
                    return false;
                }
            }

            return true;
        };

        for (size_t l = s.size(); 0 < l; --l) {
            for (size_t pos = 0; (pos + l - 1) < s.size(); ++pos) {
                if (checkPalindrome(pos, l)) {
                    return s.substr(pos, l);
                }
            }
        }

        return "";
    }

    // DP, Time: O(n^3), Space: O(n^2)
    string dp1(const string& s) {
        size_t pos = 0, maxLen = s.empty() ? 0 : 1;

        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), true));
        for (size_t len = 2; len <= s.size(); ++len) {
            for (size_t lft = 0, rht = lft + len - 1; rht < s.size(); ++lft, ++rht) {
                dp[lft][rht] = (s[lft] == s[rht]) && dp[lft + 1][rht - 1];
                if (dp[lft][rht] && maxLen < len) {
                    pos = lft;
                    maxLen = len;
                }
            }
        }

        return s.substr(pos, maxLen);
    }

    // DP, Time: O(n^3), Space: O(n)
    string dp2(const string& s) {
        size_t pos = 0, maxLen = s.empty() ? 0 : 1;

        vector<vector<bool>> dp(2, vector<bool>(s.size(), true));
        for (size_t len = 2; len <= s.size(); ++len) {
            for (size_t lft = 0, rht = lft + len - 1; rht < s.size(); ++lft, ++rht) {
                auto& cache = dp[(len % 2 == 0 ? 0 : 1)];
                cache[lft] = (s[lft] == s[rht]) && cache[lft + 1];
                if (cache[lft] && maxLen < len) {
                    pos = lft;
                    maxLen = len;
                }
            }
        }

        return s.substr(pos, maxLen);
    }

    // iterative, Time: O(n^3), Space: O(1)
    string iterative(const string& s) {
        size_t pos = 0, maxLen = 0;

        for (size_t i = 0; i < s.size() && maxLen < ((s.size() - i) * 2 + 1);) {
            size_t lft = i, rht = i;
            while ((rht + 1) < s.size() && s[rht + 1 ] == s[rht]) {
                ++rht;
            }
            i = rht + 1;

            while (0 < lft && (rht + 1) < s.size() && s[lft - 1] == s[rht + 1]) {
                --lft, ++rht;
            }

            size_t len = rht - lft + 1;
            if (maxLen < len) {
                pos = lft;
                maxLen = len;
            }
        }

        return s.substr(pos, maxLen);
    }

    string longestPalindrome(string s) {
        //return bruteforce(s);
        //return dp1(s);
        //return dp2(s);

        return iterative(s);
    }
};
