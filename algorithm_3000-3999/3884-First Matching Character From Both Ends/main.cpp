class Solution {
public:
    int firstMatchingIndex(string s) {
        for (int i = 0, n = s.size(); i * 2 < n; ++i) {
            if (s[i] == s[n - i - 1]) {
                return i;
            }
        }

        return -1;
    }
};
