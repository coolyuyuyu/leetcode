class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        size_t n = s.size();

        // suffix[i]: the longest length k such that s[0:k-1] == s[i-k+1:i]
        vector<size_t> suffix(n);
        suffix[0] = 0;
        for (size_t i = 1; i < n; ++i) {
            size_t j = suffix[i - 1];
            while (0 < j && s[j] != s[i]) {
                j = suffix[j - 1];
            }
            suffix[i] = j + (s[j] == s[i] ? 1 : 0);
        }

        return 0 < suffix[n - 1] && ((n % (n - suffix[n - 1])) == 0);
    }
};

/*
[A B C] [A B C] [A B C]
[A B C] [A B C] [A B C] [A B C]
*/
