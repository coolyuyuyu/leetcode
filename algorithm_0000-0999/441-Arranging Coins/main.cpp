class Solution {
public:
    int bsearch(int n) {
        int lo = 1, hi = n;
        while (lo < hi) {
            int mid = hi - (hi - lo) / 2;
            if (1L * mid * (mid + 1) / 2 <= n) {
                lo = mid;
            }
            else {
                hi = mid - 1;
            }
        }

        return lo;
    }

    int math(int n) {
        // assume answer is k
        // => (k)(k+1)/2 <= n < (k+1)(k+2)/2
        // => (k)(k+1) <= 2n < (k+1)(k+2)
        // => (k)^2 < 2n < (k+2)^2
        // => sqrt(2n) - 2 < k < sqrt(2n)
        for (int k = sqrt(1L * 2 * n) - 2 + 1; k < sqrt(1L * 2 * n); ++k) {
            if (1L * k * (k + 1) <= 1L * 2 * n && 1L * 2 * n < 1L * (k + 1) * (k + 2)) {
                return k;
            }
        }

        assert(false);
        return 0;
    }

    int arrangeCoins(int n) {
        //return bsearch(n);
        return math(n);
    }
};
