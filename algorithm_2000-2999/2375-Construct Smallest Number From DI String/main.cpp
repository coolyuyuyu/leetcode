class Solution {
public:
    string smallestNumber(string pattern) {
        pattern = "I" + pattern;
        int n = pattern.size();

        string ret(n, '\0');
        for (int i = 0, cnt = 1; i < n; i += cnt, cnt = 1) {
            while (i + cnt < n && pattern[i + cnt] == 'D') {
                ++cnt;
            }
            for (int j = i; j < i + cnt; ++j) {
                ret[j] = '1' + i + cnt - (j - i) - 1;
            }
        }

        return ret;
    }
};
