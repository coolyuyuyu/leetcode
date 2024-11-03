class Solution {
public:
    string makeFancyString(string s) {
        string ret;
        for (int i = 0, cnt = 0; i < s.size(); ++i) {
            if (ret.empty() || ret.back() != s[i]) {
                ret += s[i];
                cnt = 1;
            }
            else if (cnt < 2){
                ret += s[i];
                ++cnt;
            }
        }

        return ret;
    }
};
