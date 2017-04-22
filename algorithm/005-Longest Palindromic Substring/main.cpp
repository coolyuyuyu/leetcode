class Solution {
public:
    string longestPalindrome(string s) {
        int pos = 0, len = 0;
        for (int i = 0; i < s.size() && len < (s.size() - i) * 2 + 1; ) {
            int lft = i, rht = i;
            while ((rht + 1 < s.size()) && (s[rht] == s[rht + 1])) {
                ++rht;
            }
            i = rht + 1;

            while ((0 < lft) && (rht + 1 < s.size()) && (s[lft - 1] == s[rht + 1])) {
                --lft;
                ++rht;
            }

            int l = rht - lft + 1;
            if (len < l) {
                len = l;
                pos = lft;
            }
        }

        return s.substr(pos, len);
    }
};