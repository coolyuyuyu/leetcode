class Solution {
public:
    inline int c2n(char c) {
        switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
        }
    }

    int romanToInt(string s) {
        if (s.empty()) {
            return 0;
        }

        char nxtChar = s.back();
        int nxtVal = c2n(nxtChar);
        int result = nxtVal;
        for (string::const_reverse_iterator ritr = s.rbegin() + 1; ritr != s.rend(); ++ritr) {
            int curVal = c2n(*ritr);
            if (nxtVal <= curVal) {
                result += curVal;
            }
            else {
                result -= curVal;
            }    
            nxtVal = curVal;
        }
        return result;
    }
};