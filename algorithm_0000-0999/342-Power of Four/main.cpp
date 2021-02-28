class Solution {
public:
    bool isPowerOfFour(int num) {
#define MASK_00101010101010101010101010101010 (0x2AAAAAAA)
        return (0 < num) && ((num & num - 1) == 0) && ((num & MASK_00101010101010101010101010101010) == 0);
    }
};