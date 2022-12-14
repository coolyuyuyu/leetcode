class Solution {
public:
    bool isPalindrome(string s) {
        for (size_t lft = 0, rht = s.size() - 1; lft < rht; ) {
            if (!isalnum(s[lft])) {
                ++lft;
                continue;
            }
            if (!isalnum(s[rht])) {
                --rht;
                continue;
            }
            if (toupper(s[lft]) != toupper(s[rht])) {
                return false;
            }

            ++lft, --rht;
        }

        return true;

    }
};
