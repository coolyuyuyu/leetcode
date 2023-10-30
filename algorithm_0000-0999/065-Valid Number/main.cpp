
class Solution {
public:
    bool isNumber(string s) {
        std::function<bool(const string&, int)> checkNum = [](const string& s, int maxCntDot) {
            int i = 0, n = s.size();
            if (i < n && (s[0] == '+' || s[0] == '-')) {
                ++i;
            }
            if (i == n) { return false; }
            if (s[i] == '.' && i + 1 == n) { return false; }

            int cntDot = 0;
            for (; i < n; ++i) {
                if (s[i] == '.') {
                    ++cntDot;
                }
                else if (!isdigit(s[i])) {
                    return false;
                }
            }

            return cntDot <= maxCntDot;
        };

        int cntExp = 0, posExp;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'e' || s[i] == 'E') {
                cntExp += 1;
                posExp = i;
            }
        }
        if (cntExp > 1) { return false;}
        if (cntExp == 0) { return checkNum(s, 1); }
        else { return checkNum(s.substr(0, posExp), 1) && checkNum(s.substr(posExp + 1), 0); }
    }
};
