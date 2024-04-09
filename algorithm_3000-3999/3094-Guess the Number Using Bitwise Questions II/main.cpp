/** 
 * Definition of commonBits API.
 * int commonBits(int num);
 */

class Solution {
public:
    int findNumber() {
        int ret = 0;
        for (int i = 1; i < (1 << 30); i <<= 1) {
            int cnt1 = commonBits(i);
            int cnt2 = commonBits(i);
            if (cnt1 > cnt2) {
                ret |= i;
            }
        }

        return ret;
    }
};
