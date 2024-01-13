class Solution {
public:
    int minSteps(string s, string t) {
        int cnts[26];
        std::fill(cnts, cnts + 26, 0);

        for (char c : s) {
            ++cnts[c - 'a'];
        }
        for (char c : t) {
            --cnts[c - 'a'];
        }

        int ret = 0;
        for (int i = 0; i < 26; ++i) {
            if (cnts[i] > 0) {
                ret += cnts[i];
            }
        }

        return ret;
    }
};
