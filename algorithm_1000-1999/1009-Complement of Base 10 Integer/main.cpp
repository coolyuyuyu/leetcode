class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) { return 1; }

        int ret = n;
        for (int i = 0; n; ++i, n >>= 1) {
            ret ^= (1 << i);
        }

        return ret;
    }
};
