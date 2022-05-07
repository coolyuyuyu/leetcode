class Solution {
public:
    // Time: O(N), Space: O(1)
    long long numberOfWays(string s) {
        long long n0(0), n10(0), n010(0), n1(0), n01(0), n101(0);
        for (char c : s) {
            if (c == '0') {
                ++n0;
                n10 += n1;
                n010 += n01;
            }
            else {
                ++n1;
                n01 += n0;
                n101 += n10;
            }
        }

        return n010 + n101;
    }
};
