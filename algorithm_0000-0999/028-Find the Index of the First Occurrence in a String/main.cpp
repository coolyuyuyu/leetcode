class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();

        // lps[i] the maximum value k such that needle[0:k-1] == needle[i-k+1:i]
        int lps[n];
        lps[0] = 0;
        for (int i = 1; i < n; ++i) {
            int j = lps[i - 1];
            while (0 < j && needle[j] != needle[i]) {
                j = lps[j - 1];
            }
            lps[i] = j + (needle[j] == needle[i] ? 1 : 0);
        }

        int j = 0;
        for (int i = 0; i < m; ++i) {
            while (0 < j && haystack[i] != needle[j]) {
                j = lps[j - 1];
            }
            j = j + (haystack[i] == needle[j] ? 1 : 0);

            if (j == n) {
                return i - n + 1;
            }
        }

        return -1;
    }
};
