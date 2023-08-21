class Solution {
public:
    string longestPrefix(string s) {
        // lps[i]: the maximum value k such that s[0:k-1] == s[i-k+1:i]
        vector<size_t> lps(s.size());
        lps[0] = 0;
        for (size_t i = 1; i < s.size(); ++i) {
            size_t j = lps[i - 1];
            while (0 < j && s[j] != s[i]) {
                j = lps[j - 1];
            }
            lps[i] = j + (s[j] == s[i] ? 1 : 0);
        }

        return s.substr(0, lps[s.size() - 1]);
    }
};
