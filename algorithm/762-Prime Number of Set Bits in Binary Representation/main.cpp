class Solution {
public:
    int popcount(uint32_t n) {
#define MASK_01010101010101010101010101010101 (0x55555555)
#define MASK_00110011001100110011001100110011 (0x33333333)
#define MASK_00001111000011110000111100001111 (0x0F0F0F0F)
#define MASK_00000000111111110000000011111111 (0x00FF00FF)
#define MASK_00000000000000001111111111111111 (0x0000FFFF)
#define MASK_00000000000000000000000011111111 (0x000000FF)
        n -= ((n >> 1) & MASK_01010101010101010101010101010101);
        n = (n & MASK_00110011001100110011001100110011) + ((n >> 2) & MASK_00110011001100110011001100110011);
        n = (n + (n >> 4)) & MASK_00001111000011110000111100001111;
        n += (n >> 8);
        n += (n >> 16);
        return n & MASK_00000000000000000000000011111111;
    }

    int countPrimeSetBits(int L, int R) {
        int ans = 0;
        for (int i = L; i <= R; ++i) {
            switch (popcount(i)) {
            case 2:
            case 3:
            case 5:
            case 7:
            case 11:
            case 13:
            case 17:
            case 19:
                ++ans;
                break;
            default:
                break;
            }
        }

        return ans;
    }
};