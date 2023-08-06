class Solution {
public:
    string finalString(string s) {
        string ret;
        for (char c : s) {
            if (c == 'i') {
                std::reverse(ret.begin(), ret.end());
            }
            else {
                ret += c;
            }
        }

        return ret;
    }
};
