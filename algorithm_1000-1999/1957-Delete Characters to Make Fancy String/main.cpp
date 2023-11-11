class Solution {
public:
    string makeFancyString(string s) {
        string ret = s.substr(0, 2);
        for (int i = 2; i < s.size(); ++i) {
            if (ret[ret.size() - 2] == ret[ret.size() - 1] && ret[ret.size() - 1] == s[i]) {
                continue;
            }
            ret.push_back(s[i]);
        }

        return ret;
    }
};
