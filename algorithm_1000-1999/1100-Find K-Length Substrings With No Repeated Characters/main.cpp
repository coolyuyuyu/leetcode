class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        vector<int> freqs(26, 0);

        int ret = 0;
        for (int i = 0, n = s.size(), diffCnt = 0; i < n; ++i) {
            if (++freqs[s[i] - 'a'] == 1) {
                ++diffCnt;
            }

            if (i + 1 >= k) {
                if (diffCnt == k) {
                    ++ret;
                }

                if (--freqs[s[i - k + 1] - 'a'] == 0) {
                    --diffCnt;
                }
            }
        }

        return ret;
    }
};
