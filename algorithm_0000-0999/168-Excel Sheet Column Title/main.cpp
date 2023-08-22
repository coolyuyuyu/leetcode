class Solution {
public:
    string convertToTitle(int n) {
        string s;
        while (n) {
            s += ('A' + (n - 1) % 26);
            n = (n - 1) / 26;
        }
        std::reverse(s.begin(), s.end());

        return s;
    }
};