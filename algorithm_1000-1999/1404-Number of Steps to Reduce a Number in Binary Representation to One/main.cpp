class Solution {
public:
    int numSteps(string s) {
        int ret = 0;
        int carry = 0;
        for (int i = s.size(); 1 < i--;) {
            int d = (s[i] - '0') + carry;
            if (d == 1) {
                carry = 1;
                ++ret;
            }
            ++ret;
        }

        return ret + carry;
    }
};
