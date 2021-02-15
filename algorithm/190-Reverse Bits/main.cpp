class Solution {
public:
    uint32_t reverseBits_linerScan(uint32_t n) {
        uint32_t m = 0;
        for (int i = 0; i < 32; ++i) {
            m <<= 1;
            m |= (n & 1);
            n >>= 1;
        }

        return m;
    }

    uint32_t reverseBits_swapBits(uint32_t n) {
        for (int i = 0, j = 31; i < 16; ++i, --j) {
            if (((n >> i) & 1) != ((n >> j) & 1)) {
                n ^= ((1 << j) | (1 << i));
            }
        }

        return n;
    }

    uint32_t reverseBits(uint32_t n) {
        //return reverseBits_linerScan(n);
        return reverseBits_swapBits(n);
    }
};