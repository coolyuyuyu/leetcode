class Solution {
public:
    int removePalindromeSub(string s) {
        std::function<bool(const string&)> checkPalinfrome = [](const string& s) {
            for (int lft = 0, rht = s.size() - 1; lft < rht; ++lft, --rht) {
                if (s[lft] != s[rht]) {
                    return false;
                }
            }
            return true;
        };

        return checkPalinfrome(s) ? 1 : 2;
    }
};
