class Solution {
public:
    int minimumLength(string s) {
        int lft = 0, rht = s.size() - 1;
        while (lft < rht && s[lft] == s[rht]) {
            char c = s[lft];
            for (; lft < s.size() && s[lft] == c; ++lft)
                ;
            for (; lft < rht && s[rht] == c; --rht)
                ;
        }

        return rht - lft + 1;
    }
};
