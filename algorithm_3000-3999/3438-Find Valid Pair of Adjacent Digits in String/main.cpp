class Solution {
public:
    string findValidPair(string s) {
        vector<int> cnts(10, 0);
        for (char c : s) {
            ++cnts[c - '0'];
        }

        for (int i = 0; i + 1 < s.size(); ++i) {
            if (s[i] == s[i + 1]) { continue; }
            if (cnts[s[i] - '0'] == s[i] - '0' && cnts[s[i + 1] - '0'] == s[i + 1] - '0') {
                return s.substr(i, 2);
            }
        }

        return "";
    }
};
