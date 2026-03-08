class Solution {
public:
    uint32_t linear_scan(uint32_t n) {
        uint32_t ret = 0;
        for (int i = 0; i < 32; ++i) {
            ret <<= 1;
            ret |= (n & 1);
            n >>= 1;
        }

        return ret;
    }

    uint32_t lftrht_swap(uint32_t n) {
        for (int l = 0, r = 31; l < r; ++l, --r) {
            if (((n >> l) & 1) != ((n >> r) & 1)) {
                n ^= (1 << l) | (1 << r);
            }
        }

        return n;
    }

    uint32_t reverseBits(uint32_t n) {
        //return linear_scan(n);
        return lftrht_swap(n);
    }
};
