class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        vector<int> cnts(26, 0);
        int ret = 0;
        for (int i = 0, j = 0, n = s.size(), meetCnt = 0; i < n; ++i) {
            for (; j < n && meetCnt == 0; ++j) {
                if (++cnts[s[j] - 'a'] == k) {
                    ++meetCnt;
                }
            }

            if (meetCnt > 0) {
                ret += n - j + 1;
            }

            if (cnts[s[i] - 'a']-- == k) {
                --meetCnt;
            }
        }

        return ret;
    }
};
