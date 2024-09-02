class Solution {
public:
    string getSmallestString(string s) {
        int n = s.size();
        for (int i = 0; i + 1 < n; ++i) {
            int d1 = s[i] - '0', d2 = s[i + 1] - '0';
            if (((d1 ^ d2) & 1) == 0 && d1 > d2) {
                std::swap(s[i], s[i + 1]);
                break;
            }
        }

        return s;
    }
};
