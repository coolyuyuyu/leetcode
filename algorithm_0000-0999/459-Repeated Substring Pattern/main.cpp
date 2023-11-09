class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();

        // lps[i]: the longest length k such that s[0:k-1] == s[i-k+1:i]
        int lps[n];
        lps[0] = 0;
        for (int i = 1; i < n; ++i) {
            int j = lps[i - 1];
            while (0 < j && s[j] != s[i]) {
                j = lps[j - 1];
            }
            lps[i] = j + (s[j] == s[i] ? 1 : 0);
        }

        return 0 < lps[n - 1] && n % (n - lps[n - 1]) == 0;
    }
};
