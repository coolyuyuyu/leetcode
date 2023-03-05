class Solution {
public:
    vector<size_t> computeLPS(const string& s) {
        // dp[i]: the longest length k such that dp[0:k-1] == dp[i-k+1:i]
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

    int kmp(const string& s, const string& t) {
        if (s.size() < t.size()) {
            return -1;
        }

        vector<size_t> lps = computeLPS(t);

        // dp[i]: the longest length k such that t[0:k-1] == s[i-k+1:i]
        vector<size_t> dp(s.size());
        dp[0] = (s[0] == t[0] ? 1 : 0);
        if (dp[0] == 1 && t.size() == 1) {
            return 0;
        }
        for (size_t i = 1; i < s.size(); ++i) {
            size_t j = dp[i - 1];
            while (0 < j && t[j] != s[i]) {
                j = lps[j - 1];
            }
            dp[i] = j + (t[j] == s[i] ? 1 : 0);

            if (dp[i] == t.size()) {
                return i - t.size() + 1;
            }
        }

        return -1;
    }

    int strStr(string haystack, string needle) {
        return kmp(haystack, needle);
    }
};
