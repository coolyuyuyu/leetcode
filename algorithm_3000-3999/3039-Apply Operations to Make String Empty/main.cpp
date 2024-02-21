class Solution {
public:
    string lastNonEmptyString(string s) {
        int cnts[26];
        int indexes[26];
        std::fill(cnts, cnts + 26, 0);
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            ++cnts[c - 'a'];
            indexes[c - 'a'] = i;
        }
        int maxCnt = *std::max_element(cnts, cnts + 26);

        string ret;
        for (int i = 0; i < 26; ++i) {
            if (cnts[i] == maxCnt) {
                ret.push_back('a' + i);
            }
        }
        std::sort(ret.begin(), ret.end(), [&](char c1, char c2){ return indexes[c1 - 'a'] < indexes[c2 - 'a']; });

        return ret;
    }
};
