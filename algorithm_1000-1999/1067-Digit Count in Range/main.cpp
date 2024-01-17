class Solution {
public:
    // 233. Number of Digit One
    int countDigitD(int n, int d) {
        // n = 5 6 7 8 9
        // i = 4 3 2 1 0
        // for each i, find how many digits d in [0,n]

        if (n == 0) {
            return 0;
        }

        int len = 0;
        for (int x = n; x; ++len) {
            x /= 10;
        }

        long pow10[len + 1];
        pow10[0] = 1;
        for (int i = 1; i <= len; ++i) {
            pow10[i] = pow10[i - 1] * 10;
        }

        long ret = 0;
        for (int i = 0; i < len; ++i) {
            long lftNum = n / pow10[i + 1];
            long rhtNum = n % pow10[i];
            int digit = (n / pow10[i]) % 10;

            ret += (d == 0 ? (lftNum - 1) : lftNum) * pow10[i];
            if (digit < d) {
            }
            else if (digit == d) {
                ret += rhtNum + 1;
            }
            else {
                ret += pow10[i];
            }
        }

        return ret;
    }

    int digitsCount(int d, int low, int high) {
        return countDigitD(high, d) - countDigitD(low - 1, d);
    }
};
