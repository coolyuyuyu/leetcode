class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        int cnt1 = std::count(s.begin(), s.end(), '1');

        for (char& c : s) {
            c = '0';
        }

        if (cnt1 > 0) {
            s.back() = '1';
        }
        for (int i = 0; i + 1 < cnt1; ++i) {
            s[i] = '1';
        }

        return s;
    }
};
