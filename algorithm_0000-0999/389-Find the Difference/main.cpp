class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> cnts(26, 0);
        for (char c : s) {
            ++cnts[c - 'a'];
        }

        char ret;
        for (char c : t) {
            if (--cnts[c - 'a'] < 0) {
                ret = c;
                break;
            }
        }

        return ret;
    }
};