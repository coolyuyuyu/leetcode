class Solution {
public:
    int numberOfSpecialSubstrings(string s) {
        vector<bool> repeated(26, false);

        int ret = 0;
        for (int lft = 0, rht = 0; lft < s.size(); ++lft) {
            for (; rht < s.size() && !repeated[s[rht] - 'a']; ++rht) {
                repeated[s[rht] - 'a'] = true;
            }

            ret += (rht - lft);

            repeated[s[lft] - 'a'] = false;
        }

        return ret;
    }
};
