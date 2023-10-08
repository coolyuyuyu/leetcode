class Solution {
public:
    int countLetters(string s) {
        int ret = 0;

        char c = '\0';
        int cnt = 0;
        for (int i = 0, n = s.size(); i <= n; ++i) {
            if (i == n || c != s[i]) {
                ret += (cnt) * (cnt + 1) / 2;

                if (i < n) {
                    c = s[i];
                    cnt = 1;
                }
            }
            else {
                ++cnt;
            }
        }

        return ret;
    }
};
