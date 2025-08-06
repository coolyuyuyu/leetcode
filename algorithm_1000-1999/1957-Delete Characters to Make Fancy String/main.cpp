class Solution {
public:
    string makeFancyString(string s) {
        string ret;
        for (int i = 0, cnt = 0; i < s.size(); ++i) {
            if (i == 0 || s[i] != ret.back()) {
                cnt = 0;
            }
            ++cnt;
            if (cnt <= 2) {
                ret.push_back(s[i]);
            }
        }

        return ret;
    }
};
