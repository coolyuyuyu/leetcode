class Solution {
public:
    int findComplement(int num) {
        int ret = 0;
        for (int i = 0; num > 0; ++i, num >>= 1) {
            if ((num & 1) == 0) {
                ret |= (1 << i);
            }
        }

        return ret;
    }
};
