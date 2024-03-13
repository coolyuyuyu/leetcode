class Solution {
public:
    string smallestNumber(string pattern) {
        pattern = "I" + pattern;
        int n = pattern.size();

        string ret(n, ' ');
        for (int i = 0; i < n;) {
            int cnt = 1;
            while (i + cnt < n && pattern[i + cnt] == 'D') {
                ++cnt;
            }
            for (int j = 0; j < cnt; ++j) {
                ret[i + j] = '1' + i + cnt - j - 1;
            }

            i += cnt;
        }

        return ret;
    }
};
