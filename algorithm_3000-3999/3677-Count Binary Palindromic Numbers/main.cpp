class Solution {
public:
    int countBinaryPalindromes(long long n) {
        if (n == 0) { return 1; }

        int maxLen = 64 - __builtin_clzll(n);


        int ret = 1; // 0 is binary palindromic
        for (int len = 1; len < maxLen; ++len) {
            int halfLen = (len + 1) / 2;
            long long mn = 1LL << (halfLen - 1);
            long long mx = (1LL << halfLen) - 1;
            ret += (mx - mn + 1);
        }

        std::function<long long(long long)> reverseBit = [](long long num) {
            long long ret = 0;
            for (; num; num >>= 1) {
                ret <<= 1;
                ret += num & 1;
            }
            return ret;
        };
        std::function<long long(long long, int)> build = [&](long long half, int len) {
            int lftLen = (len + 1) / 2;
            int rhtLen = len - lftLen;
            if (len & 1) {
                return (half << rhtLen) + reverseBit(half >> 1);
            }
            else {
                return (half << rhtLen) + reverseBit(half);
            }
        };

        int halfLen = (maxLen + 1) / 2;
        long long lo = 1LL << (halfLen - 1);
        long long hi = (1LL << halfLen) - 1;
        long long mn = lo;
        while (lo < hi) {
            long long mid = hi - (hi - lo) / 2;
            long long pal = build(mid, maxLen);
            if (pal <= n) {
                lo = mid;
            }
            else {
                hi = mid - 1;
            }
        }
        if (build(hi, maxLen) <= n) {
            ret += (hi - mn + 1);
        }

        return ret;
    }
};
