class Solution {
public:
    int countBinarySubstrings(string s) {
        int ret = 0;
        for (int i = 1, n = s.size(), cur = 1, pre = 0; i <= n; ++i) {
            if (i >= n || s[i - 1] != s[i]) {
                ret += min(cur, pre);
                pre = cur;
                cur = 1;
            }
            else {
                ++cur;
            }
        }

        return ret;
    }
};
