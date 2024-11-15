class Solution {
public:
    bool makePalindrome(string s) {
        int cnt = 0;
        for (int lft = 0, rht = s.size() - 1; lft < rht; ++lft, --rht) {
            if (s[lft] != s[rht]) {
                if (++cnt > 2) {
                    return false;
                }
            }
        }

        return true;
    }
};
