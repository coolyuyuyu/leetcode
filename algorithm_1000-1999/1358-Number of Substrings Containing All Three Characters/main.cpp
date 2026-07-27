class Solution {
public:
    int numberOfSubstrings(string s) {
        int diffCnt = 0;
        vector<int> cnts(3, 0);

        int ret = 0;
        for (int i = 0, j = 0, n = s.size(); i < n; ++i) {
            for (; j < n && diffCnt < 3; ++j) {
                if (++cnts[s[j] - 'a'] == 1) {
                    ++diffCnt;
                }
            }

            if (diffCnt == 3) {
                ret += n - j + 1;
            }

            if (--cnts[s[i] - 'a'] == 0) {
                --diffCnt;
            }
        }

        return ret;
    }
};
