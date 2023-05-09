class Solution {
public:
    int countNumbersBeginWith(int prefix, int n) {
        int cnt = 0;
        for (long exp = 10; true; exp *= 10) {
            long lower = prefix * exp;
            long upper = prefix * exp + exp - 1;
            if (n < lower) {
                break;
            }

            if (lower <= n && n <= upper) {
                cnt += (n - lower + 1);
            }
            else {
                cnt += exp;
            }
        }

        return cnt;
    }

    int findKthNumberBeginWith(int prefix, int n, int k) {
        if (k == 0) {
            return prefix;
        }

        for (int i = (prefix == 0 ? 1 : 0); i <= 9; ++i) {
            int cnt = 1 + countNumbersBeginWith(prefix * 10 + i, n);
            if (cnt < k) {
                k -= cnt;
            }
            else {
                return findKthNumberBeginWith(prefix * 10 + i, n, k - 1);
            }
        }

        return -1;
    }

    int findKthNumber(int n, int k) {
        return findKthNumberBeginWith(0, n, k);
    }
};
