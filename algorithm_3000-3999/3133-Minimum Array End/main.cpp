class Solution {
public:
    long long minEnd(int n, int x) {
        --n;
        long long ret = x;

        for (int i = 0; n; ++i) {
            if (((ret >> i) & 1) == 0) {
                ret |= (1LL << i) * (n & 1);
                n >>= 1;
            }
        }

        return ret;
    }
};
