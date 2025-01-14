class Solution {
public:
    bool canBeValid(string s, string locked) {
        int lo = 0; // the minimal possible number of unmatched open parenthesis
        int hi = 0; // the maximal possible number of unmatched open parenthesis
        for (int i = 0, n = s.size(); i < n; ++i) {
            if (locked[i] == '1') {
                if (s[i] == '(') {
                    lo += 1;
                    hi += 1;
                }
                else {
                    lo -= 1;
                    hi -= 1;
                }
            }
            else {
                lo -= 1;
                hi += 1;
            }

            if (lo < 0) {
                lo += 2;
            }
            if (hi < 0) {
                return false;
            }
        }

        return lo == 0;
    }
};
