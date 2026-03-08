class Solution {
public:
    string reverseByType(string s) {
        string s1, s2;
        for (char c : s) {
            if (isalpha(c)) {
                s1 += c;
            }
            else {
                s2 += c;
            }
        }
        std::reverse(s1.begin(), s1.end());
        std::reverse(s2.begin(), s2.end());

        for (int i = 0, n = s.size(), i1 = 0, i2 = 0; i < n; ++i) {
            if (isalpha(s[i])) {
                s[i] = s1[i1++];
            }
            else {
                s[i] = s2[i2++];
            }
        }

        return s;
    }
};
