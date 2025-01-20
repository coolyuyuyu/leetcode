class Solution {
public:
    int preimageSizeFZF(int k) {
        long lo = 1, hi = 5e9;

        std::function<int(long)> countTrailingZero = [](long x) {
            int ret = 0;
            for (long i = 5; i <= x; i *= 5) {
                ret += x / i;
            }
            return ret;
        };

        while (lo < hi) {
            long mid = lo + (hi - lo) / 2;
            int cnt = countTrailingZero(mid);
            if (cnt > k) {
                hi = mid - 1;
            }
            else if (cnt < k) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }

        if (lo > hi) {
            return 0;
        }
        else if (lo == hi && countTrailingZero(lo) == k) {
            return 5;
        }
        else {
            return 0;
        }
    }
};
