class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();

        int cnt = 0;
        for (char c : s) {
            if (c == '1') {
                ++cnt;
            }
        }

        string ret(n, '0');
        for (int i = 0; i + 1 < cnt; ++i) {
            ret[i] = '1';
        }
        ret.back() = '1';

        return ret;
    }
};
