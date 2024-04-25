class Solution {
public:
    int countLetters(string s) {
        int n = s.size();

        int ret = 0;
        for (int i = 0, cnt = 0; i < n; ++i) {
            cnt = ((i == 0 || s[i - 1] != s[i])? 1 : cnt + 1);
            ret += cnt;
        }

        return ret;
    }
};
