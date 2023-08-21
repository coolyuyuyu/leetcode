class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        size_t n = s.size();

        // lps[i]: the maximum value k such that s[0:k-1] == s[i-k+1:i]
        vector<size_t> lps(n);
        lps[0] = 0;
        for (size_t i = 1; i < n; ++i) {
            size_t j = lps[i - 1];
            while (0 < j && s[j] != s[i]) {
                j = lps[j - 1];
            }
            lps[i] = j + (s[i] == s[j] ? 1 : 0);
        }

        return 0 < lps[n - 1] && (n % (n - lps[n - 1])) == 0;
    }
};
