class Solution {
public:
    string convertToTitle(int n) {
        string s;
        while (n != 0) {
            s.push_back((n - 1) % 26 + 'A');
            n = (n - 1) / 26;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};