class Solution {
public:
    bool isMatchRecursive1(string s, string p) {
        if (p.empty()) {
            return s.empty();
        }

        bool firstMatch = !s.empty() && (s[0] == p[0] || p[0] == '.');
        if (2 <= p.size() && p[1] == '*') {
            return (firstMatch && isMatchRecursive1(s.substr(1), p)) || isMatchRecursive1(s, p.substr(2));
        }
        else {
            return firstMatch && isMatchRecursive1(s.substr(1), p.substr(1));
        }
    }

    bool isMatchRecursive2(const string& s, size_t sIndex, const string& p, size_t pIndex) {
        if (p.size() <= pIndex) {
            return s.size() <= sIndex;
        }

        bool firstMatch = (sIndex < s.size()) && (s[sIndex] == p[pIndex] || p[pIndex] == '.');
        if (2 <= p.size() && p[pIndex + 1] == '*') {
            return (firstMatch && isMatchRecursive2(s, sIndex + 1, p, pIndex)) || isMatchRecursive2(s, sIndex, p, pIndex + 2);
        }
        else {
            return firstMatch && isMatchRecursive2(s, sIndex + 1, p, pIndex + 1);
        }
    }

    bool isMatch(string s, string p) {
        //return isMatchRecursive1(s, p);
        return isMatchRecursive2(s, 0, p, 0);
    }
};
