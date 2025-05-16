class Solution {
public:
    int M = 1e9 + 7;

    int lengthAfterTransformations(string s, int t) {
        int cnts[26], tmps[26];

        std::fill(cnts, cnts + 26, 0);
        for (char c : s) {
            ++cnts[c - 'a'];
        }
        for (; t; --t) {
            tmps[0] = cnts[25];
            tmps[1] = (cnts[0] + cnts[25]) % M;
            for (int i = 2; i < 26; ++i) {
                tmps[i] = cnts[i - 1];
            }
            std::copy(tmps, tmps + 26, cnts);
        }

        int ret = 0;
        for (int i = 0; i < 26; ++i) {
            ret = (ret + cnts[i]) % M;
        }

        return ret;
    }
};
