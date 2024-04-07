class Solution {
public:
    bool checkValidString(string s) {
        int lo = 0; // the minimal possible number of unmatched open parenthesis
        int hi = 0; // the maximal possible number of unmatched open parenthesis

        for (char c : s) {
            if (c == '(') {
                ++lo;
                ++hi;
            }
            else if (c == ')') {
                --lo;
                --hi;
            }
            else {
                --lo;
                ++hi;
            }

            if (lo < 0) {
                lo = 0;
            }
            if (hi < 0) {
                return false;
            }
        }

        return lo == 0;
    }
};
