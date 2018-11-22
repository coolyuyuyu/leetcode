class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_set<char> chars;
        for (char c : s) {
            if (chars.find(c) != chars.end()) {
                chars.erase(c);
            }
            else {
                chars.insert(c);
            }
        }

        if (2 <= chars.size()) {
            return false;
        }
        else if (chars.size() == 1) {
            return s.size() % 2 == 1;
        }
        else {
            return true;
        }
    }
};
