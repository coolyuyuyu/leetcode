class Solution {
public:
    int M = 1e9 + 7;

    int countHomogenous(string s) {
        int n = s.size();

        int ret = 0;
        for (int i = 0, cnt = 0; i < n; ++i) {
            if (i == 0 || s[i - 1] != s[i] ) {
                cnt = 1;
            }
            else {
                ++cnt;
            }
            ret = (ret + cnt) % M;
        }

        return ret;
    }
};
