class Solution {
public:
    vector<size_t> longestPrefix(const string& s) {
        // suffix array
        // dp[i]: the longest length k such that s[0:k-1] = s[i-k+1:i]
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

    // kmp
    string shortestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }

        size_t n = s.size();

        string t = s;
        std::reverse(t.begin(), t.end());
        vector<size_t> suffix = longestPrefix(s);
        
        size_t dp = (s[0] == t[0] ? 1 : 0);
        for (size_t i = 1; i < n; ++i) {
            size_t j = dp;
            while (0 < j && s[j] != t[i]) {
                j = suffix[j - 1];
            }
            dp = j + (s[j] == t[i] ? 1 : 0);
        }

        string ret = t.substr(0, n - dp) + s
        return ret;
    }
};

/*
s': reverse of s
decompose s as :    A A' B
reverse s as t : B' A A'

Find the shortest B'
=> Find the longest length k such that s[0:k-1] = t[i-k+1:i]
*/
