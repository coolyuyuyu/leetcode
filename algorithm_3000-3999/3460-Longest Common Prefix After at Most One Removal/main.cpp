class Solution {
public:
    int longestCommonPrefix(string s, string t) {
        int ret = 0;
        for (int i = 0, j = 0, removed = 0; i < s.size() && j < t.size();) {
            if (s[i] == t[j]) {
                ++i, ++j;
                ++ret;
            }
            else if (!removed) {
                removed = 1;
                ++i;
            }
            else {
                break;
            }
        }

        return ret;
    }
};
