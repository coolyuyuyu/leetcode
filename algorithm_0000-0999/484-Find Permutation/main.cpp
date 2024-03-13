class Solution {
public:
    vector<int> findPermutation(string s) {
        s = "I" + s;
        int n = s.size();

        vector<int> ret(n);
        for (int i = 0; i < n;) {
            int cnt = 1;
            while (i + cnt < n && s[i + cnt] == 'D') {
                ++cnt;
            }
            for (int j = 0; j < cnt; ++j) {
                ret[i + j] = i + cnt - j;
            }

            i += cnt;
        }

        return ret;
    }
};
