class Solution {
public:
    string toLowerCase(string s) {
        for (char& c : s) {
            if ('A' <= c && c <= 'Z') {
                c = c - 'A' + 'a';
            }
        }

        return s;
    }
};
