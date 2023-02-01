class Solution {
public:

    vector<size_t> longestPrefix(const string& s) {
        // suffix array
        // dp[i]: the maximal value k such that s[0:k-1] == s[i-k+1:i]
        vector<size_t> dp(s.size());
        dp[0] = 0;
        for (size_t i = 1; i < s.size(); ++i) {
            size_t j = dp[i - 1];
            while (0 < j  && s[j] != s[i]) {
                j = dp[j - 1];
            }
            dp[i] = j + (s[j] == s[i] ? 1 : 0);
        }

        return dp;
    }

    int dp1(const string& s, const string& t) {
        vector<size_t> suffix = longestPrefix(t);

        // kmp
        // dp[i]: the maximum value k such that s[i-k+1:i] == t[0:k-1]
        vector<size_t> dp(s.size());
        dp[0] = (s[0] == t[0] ? 1 : 0);
        if (dp[0] == 1 && t.size() == 1) {
            return 0;
        }
        for (size_t i = 1; i < s.size(); ++i) {
            size_t j = dp[i - 1];
            while (0 < j && s[i] != t[j]) {
                j = suffix[j - 1];
            }
            dp[i] = j + (s[i] == t[j] ? 1 : 0);

            if (dp[i] == t.size()) {
                return i - t.size() + 1;
            }
        }

        return -1;
    }

    // space optimized
    int dp2(const string& s, const string& t) {
        vector<size_t> suffix = longestPrefix(t);

        // kmp
        // dp[i]: the maximum value k such that s[i-k+1:i] == t[0:k-1]
        // cur: dp[i], pre: dp[i-1]
        size_t cur = (s[0] == t[0] ? 1 : 0);
        if (cur == 1 && t.size() == 1) {
            return 0;
        }
        size_t pre = cur;
        for (size_t i = 1; i < s.size(); ++i) {
            size_t j = pre;
            while (0 < j && s[i] != t[j]) {
                j = suffix[j - 1];
            }
            cur = j + (s[i] == t[j] ? 1 : 0);

            if (cur == t.size()) {
                return i - t.size() + 1;
            }

            pre = cur;
        }

        return -1;
    }

    int strStr(string haystack, string needle) {
        //return dp1(haystack, needle);
        return dp2(haystack, needle);
    }
};
