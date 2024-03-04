/** 
 * Definition of commonSetBits API.
 * int commonSetBits(int num);
 */

class Solution {
public:
    int findNumber() {
        int ret = 0;
        for (int i = 0, num = 1; i < 31; ++i, num <<= 1) {
            if (commonSetBits(num) > 0) {
                ret |= num;
            }
        }

        return ret;
    }
};
