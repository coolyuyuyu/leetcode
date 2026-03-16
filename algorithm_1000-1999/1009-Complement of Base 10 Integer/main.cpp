class Solution {
public:
    int f1(int n) {
        if (n == 0) { return 1; }

        int ret = n;
        for (int i = 0; n; ++i, n >>= 1) {
            ret ^= (1 << i);
        }

        return ret;
    }

    int f2(int n) {
        if (n == 0) { return 1; }
        int lz = __builtin_clz(n);
        return n ^ ((1 << (32 - lz)) - 1);
    }

    int bitwiseComplement(int n) {
        //return f1(n);
        return f2(n);
    }
};
