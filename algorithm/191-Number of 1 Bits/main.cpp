class Solution {
public:
#define MASK_01010101010101010101010101010101 (0x55555555)
#define MASK_00110011001100110011001100110011 (0x33333333)
#define MASK_00001111000011110000111100001111 (0x0F0F0F0F)
#define MASK_00000000111111110000000011111111 (0x00FF00FF)
#define MASK_00000000000000001111111111111111 (0x0000FFFF)
#define MASK_00000000000000000000000011111111 (0x000000FF)
    int popcount_0(uint32_t n) {
        n = (n & MASK_01010101010101010101010101010101) + ((n >> 1) & MASK_01010101010101010101010101010101);
        n = (n & MASK_00110011001100110011001100110011) + ((n >> 2) & MASK_00110011001100110011001100110011);
        n = (n & MASK_00001111000011110000111100001111) + ((n >> 4) & MASK_00001111000011110000111100001111);
        n = (n & MASK_00000000111111110000000011111111) + ((n >> 8) & MASK_00000000111111110000000011111111);
        n = (n & MASK_00000000000000001111111111111111) + ((n >> 16) & MASK_00000000000000001111111111111111);
        return n;
    }
    
    int popcount_1(uint32_t n) {
        n = (n & MASK_01010101010101010101010101010101) + ((n >> 1) & MASK_01010101010101010101010101010101);
        n = (n & MASK_00110011001100110011001100110011) + ((n >> 2) & MASK_00110011001100110011001100110011);
        n = (n + (n >> 4)) & MASK_00001111000011110000111100001111; 
        n = (n + (n >> 8)) & MASK_00000000111111110000000011111111;
        n = (n + (n >> 16)) & MASK_00000000000000001111111111111111;
        return n;
    }
    
    int popcount_2(uint32_t n) {
        n = (n & MASK_01010101010101010101010101010101) + ((n >> 1) & MASK_01010101010101010101010101010101);
        n = (n & MASK_00110011001100110011001100110011) + ((n >> 2) & MASK_00110011001100110011001100110011);
        n = (n + (n >> 4)) & MASK_00001111000011110000111100001111; 
        n += (n >> 8);
        n += (n >> 16);
        return n & MASK_00000000000000000000000011111111;
    }
    
    int popcount_3(uint32_t n) {
        n -= ((n >> 1) & MASK_01010101010101010101010101010101);
        n = (n & MASK_00110011001100110011001100110011) + ((n >> 2) & MASK_00110011001100110011001100110011);
        n = (n + (n >> 4)) & MASK_00001111000011110000111100001111; 
        n += (n >> 8);
        n += (n >> 16);
        return n & MASK_00000000000000000000000011111111;
    }

    int hammingWeight(uint32_t n) {
        return popcount_3(n);
    }
};