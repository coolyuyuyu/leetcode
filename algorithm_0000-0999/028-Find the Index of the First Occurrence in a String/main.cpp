class Solution {
public:
    vector<size_t> longestPrefix(const string& s) {
        // suffix array
        // dp[i]: the longest length k such that s[0:k-1] == s[i-k+1:i]
        vector<size_t> dp(s.size());
        dp[0] = 0;

        for (size_t i = 1; i < s.size(); ++i) {
            size_t j = dp[i - 1];
            while (0 < j && s[j] != s[i]) {
                j = dp[j - 1];
            }
            dp[i] = j + (s[j] == s[i] ? 1 : 0);
        }

        return dp;
    }

    // Space: O(len(haystack) + len(needle))
    int kmp1(const string& haystack, const string& needle) {
        if (haystack.size() < needle.size()) {
            return -1;
        }
        vector<size_t> suffix = longestPrefix(needle);

        // dp[i]: the longest length k such that needle[0:k-1] == haystack[i-k+1:i]
        vector<size_t> dp(haystack.size());
        dp[0] = (needle[0] == haystack[0] ? 1 : 0);
        if (dp[0] == 1 && needle.size() == 1) {
            return 0;
        }
        for (size_t i = 1; i < haystack.size(); ++i) {
            size_t j = dp[i - 1];
            while (0 < j && needle[j] != haystack[i]) {
                j = suffix[j - 1];
            }
            dp[i] = j + (needle[j] == haystack[i] ? 1 : 0);
            if (needle.size() <= dp[i]) {
                return i - needle.size() + 1;
            }
        }

        return -1;
    }

    // Space: O(len(needle))
    int kmp2(const string& haystack, const string& needle) {
        if (haystack.size() < needle.size()) {
            return -1;
        }
        vector<size_t> suffix = longestPrefix(needle);

        // dp[i]: the longest length k such that needle[0:k-1] == haystack[i-k+1:i]
        size_t dp = (needle[0] == haystack[0] ? 1 : 0);
        if (dp == 1 && needle.size() == 1) {
            return 0;
        }
        for (size_t i = 1; i < haystack.size(); ++i) {
            size_t j = dp;
            while (0 < j && needle[j] != haystack[i]) {
                j = suffix[j - 1];
            }
            dp = j + (needle[j] == haystack[i] ? 1 : 0);
            if (needle.size() <= dp) {
                return i - needle.size() + 1;
            }
        }

        return -1;
    }

    int strStr(string haystack, string needle) {
        // return kmp1(haystack, needle);
        return kmp2(haystack, needle);
    }
};
