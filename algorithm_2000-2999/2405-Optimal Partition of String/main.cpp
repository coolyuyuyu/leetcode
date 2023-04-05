class Solution {
public:
    int partitionString(string s) {
        int n = s.size();

        int ret = 0;
        array<bool, 26> flags;
        for (int lft = 0, rht; lft < n; lft = rht, ++ret) {
            flags.fill(false);
            for (rht = lft; rht < n && !flags[s[rht] - 'a']; ++rht) {
                flags[s[rht] - 'a'] = true;
            }
        }

        return ret;
    }
};
