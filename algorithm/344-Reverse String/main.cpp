class Solution {
public:
    string reverseString(string s) {
        int lft = 0;
        int rht = s.size() - 1;
        while (lft < rht) {
            swap(s[lft], s[rht]);
            ++lft;
            --rht;
        }
        return s;
    }
};