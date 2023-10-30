class Solution {
public:
    int lengthOfLastWord(string s) {
        int rht = s.find_last_not_of(' ');
        int lft = s.find_last_of(' ', rht);
        lft = (lft == string::npos ? 0 : lft + 1);
        return rht - lft + 1;
    }
};
