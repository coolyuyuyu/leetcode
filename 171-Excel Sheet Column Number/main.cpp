class Solution {
public:
    int titleToNumber(string s) {
        int n = 0;
        for (string::const_iterator iter = s.begin(); iter != s.end(); ++iter) {
            n *= 26;
            n += (*iter - 'A' + 1);
        }
        return n;
    }
};