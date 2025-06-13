class Solution {
public:
    int findKthNumber(int n, int k) {
        std::function<int(int)> countNumbersStartWith = [&](int prefix){
            int ret = 0;
            for (int exp = 10; true; exp *= 10) {
                long lo = 1L * prefix * exp, hi = 1L * prefix * exp + (exp - 1);
                if (n < lo) {
                    break;
                }

                if (lo <= n && n <= hi) {
                    ret += n - lo + 1;
                }
                else {
                    ret += exp;
                }
            }
            return ret;
        };

        std::function<int(int, int)> findKthNumberStartWith = [&](int prefix, int k) {
            if (k == 0) { return prefix; }

            int d = (prefix == 0 ? 1 : 0);
            for (; d <= 9; ++d) {
                int cnt = 1 + countNumbersStartWith(prefix * 10 + d);
                if (cnt < k) {
                    k -= cnt;
                }
                else {
                    break;
                }
            }
            return findKthNumberStartWith(prefix * 10 + d, k - 1);
        };

        return findKthNumberStartWith(0, k);
    }
};
