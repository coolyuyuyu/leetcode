class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size();

        int ret = 0;
        for (int i = 2; i < n; ++i) {
            if (s[i - 2] != s[i - 1] && s[i - 2] != s[i] && s[i - 1] != s[i]) {
                ++ret;
            }
        }

        return ret;
    }
};
