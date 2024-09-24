class Solution {
public:
    int findKthNumber(int n, int k) {
        std::function<int(int)> countNumberBeginWith = [&](int prefix){
            int cnt = 0;
            for (int exp = 10; true; exp *= 10) {
                long lower = 1L * prefix * exp, upper = 1L * prefix * exp + (exp - 1);
                if (lower > n) {
                    break;
                }

                if (lower <= n && n < upper) {
                    cnt += n - lower + 1;
                }
                else {
                    cnt += exp;
                }
            }
            return cnt;
        };

        std::function<int(int, int)> findKthNumberBeginWith = [&](int prefix, int k) {
            if (k == 0) {
                return prefix;
            }

            int i = (prefix == 0 ? 1 : 0);
            for (; i <= 9; ++i) {
                int cnt = 1 + countNumberBeginWith(prefix * 10 + i);
                if (cnt < k) {
                    k -= cnt;
                }
                else {
                    break;
                }
            }

            return findKthNumberBeginWith(prefix * 10 + i, k - 1);
        };

        return findKthNumberBeginWith(0, k);
    }
};
