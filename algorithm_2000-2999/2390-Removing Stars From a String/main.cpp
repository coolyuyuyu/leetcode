class Solution {
public:
    string removeStars(string s) {
        string ret;
        for (char c : s) {
            if (c == '*') {
                ret.pop_back();
            }
            else {
                ret.push_back(c);
            }
        }

        return ret;
    }
};
