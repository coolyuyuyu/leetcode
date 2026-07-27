class Solution {
public:
    int reverseDegree(string s) {
        int ret = 0;
        for (int i = 0; i < s.size(); ++i) {
            ret += (i + 1) * (26 - (s[i] - 'a'));
        }

        return ret;
    }
};
