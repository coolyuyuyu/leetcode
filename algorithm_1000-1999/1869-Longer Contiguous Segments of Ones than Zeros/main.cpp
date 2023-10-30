class Solution {
public:
    bool checkZeroOnes(string s) {
        int n = s.size();

        int len0 = 0, len1 = 0;
        for (int lft = 0; lft < n;) {
            int rht = lft;
            for (; rht < n; ++rht) {
                if (s[lft] != s[rht]) {
                    break;
                }
            }
            if (s[lft] == '0') {
                len0 = std::max(len0, rht - lft);
            }
            else {
                len1 = std::max(len1, rht - lft);
            }

            lft = rht;
        }

        return len1 > len0;
    }
};
