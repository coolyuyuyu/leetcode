class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int lft = 0, rht = s.size() - 1; lft < rht; ++lft, --rht) {
            std::swap(s[lft], s[rht]);
        }
    }
};
