class Solution {
public:
    bool isPalindrome(string s) {
        int lft = 0;
        int rht = s.size() - 1;
        while (lft < rht) {
            while (lft < rht && !isalnum(s[lft])) {
                ++lft;
            }

            while (lft < rht && !isalnum(s[rht])) {
                --rht;
            }

            if (lft < rht) {
                if (tolower(s[lft]) == tolower(s[rht])) {
                    ++lft;
                    --rht;
                }
                else {
                    return false;
                }
            }
        }
        
        return true;
    }
};