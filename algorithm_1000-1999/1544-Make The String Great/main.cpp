class Solution {
public:
    string makeGood(string s) {
        string ret;
        for (char c : s) {
            if (ret.empty()) {
                ret.push_back(c);
            }
            else if (isupper(ret.back()) && tolower(ret.back()) == c) {
                ret.pop_back();
            }
            else if (islower(ret.back()) && toupper(ret.back()) == c) {
                ret.pop_back();
            }
            else {
                ret.push_back(c);
            }
        }

        return ret;
    }
};
