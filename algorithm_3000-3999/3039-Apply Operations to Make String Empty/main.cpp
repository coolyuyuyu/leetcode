class Solution {
public:
    string lastNonEmptyString(string s) {
        int cnts[26];
        std::fill(cnts, cnts + 26, 0);
        for (char c : s) {
            ++cnts[c - 'a'];
        }
        int maxCnt = *std::max_element(cnts, cnts + 26);

        string ret;
        std::fill(cnts, cnts + 26, 0);
        for (char c : s) {
            if (++cnts[c - 'a'] == maxCnt) {
                ret += c;
            }
        }

        return ret;
    }
};
