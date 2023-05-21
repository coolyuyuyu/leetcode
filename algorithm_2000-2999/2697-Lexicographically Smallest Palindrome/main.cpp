class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.size();
        int lft, rht = (n + 1) / 2;
        if ((n % 2) == 0) {
            lft = rht - 1;
        }
        else {
            lft = rht - 2;
        }
        for (; rht < n; ++rht, --lft) {
            char c = std::min(s[lft], s[rht]);
            s[lft] = s[rht] = c;
        }

        return s;
    }
};
