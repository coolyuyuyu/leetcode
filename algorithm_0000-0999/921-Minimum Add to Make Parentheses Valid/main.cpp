class Solution {
public:
    int minAddToMakeValid(string s) {
        int mismatchOpen = 0;
        int mismatchClose = 0;
        for (char c : s) {
            if (c == '(') {
                ++mismatchOpen;
            }
            else {
                --mismatchOpen;
                if (mismatchOpen < 0) {
                    ++mismatchClose;
                    mismatchOpen = 0;
                }
            }
        }

        return mismatchOpen + mismatchClose;
    }
};
