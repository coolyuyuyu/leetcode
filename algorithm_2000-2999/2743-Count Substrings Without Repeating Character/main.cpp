class Solution {
public:
    int numberOfSpecialSubstrings(string s) {
        vector<bool> repeated(26, false);

        int ret = 0;
        for (int lft = 0, rht = 0, n = s.size(); lft < n; ++lft) {
            for (; rht < n && repeated[s[rht] - 'a'] == false; ++rht) {
                repeated[s[rht] - 'a'] = true;
            }

            ret += rht - lft;

            repeated[s[lft] - 'a'] = false;
        }

        return ret;
    }
};
