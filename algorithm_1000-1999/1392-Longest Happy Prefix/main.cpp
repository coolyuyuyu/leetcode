class Solution {
public:
    string longestPrefix(string s) {
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

        return s.substr(0, dp[s.size() - 1]);
    }
};
