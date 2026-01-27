class Solution {
public:
    long long comb(int n, int r) {
        long long ret = 1;
        for (int i = 0; i < r; ++i) {
            ret *= n - i;
            ret /= i + 1;
        }

        return ret;
    }

    long long nthSmallest(long long n, int k) {
        long long ret = 0;
        for (int i = 50; k > 0 && i >= 0; --i) {
            long long cnt = comb(i, k);
            if (cnt < n) {
                n -= cnt;
                --k;
                ret |= (1LL << i);
            }
        }

        return ret;
    }
};
