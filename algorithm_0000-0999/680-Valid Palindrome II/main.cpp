class Solution {
public:
    bool checkPalindrome(const string& s, size_t lft, size_t rht) {
        while (lft < rht) {
            if (s[lft] != s[rht]) {
                return false;
            }
            ++lft, --rht;
        }

        return true;
    }

    bool validPalindrome(string s) {
        assert(!s.empty());

        size_t lft = 0, rht = s.size() - 1;
        while (lft < rht) {
            if (s[lft] != s[rht]) {
                if (checkPalindrome(s, lft + 1, rht) || checkPalindrome(s, lft, rht - 1)) {
                    return true;
                }
                else {
                    return false;
                }
            }
            ++lft, --rht;
        }

        return true;
    }
};
