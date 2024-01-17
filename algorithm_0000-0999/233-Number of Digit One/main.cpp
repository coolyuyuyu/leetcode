class Solution {
public:
    int countDigitOne(int n) {
        // n = 5 6 7 8 9
        // i = 4 3 2 1 0
        // for each i, find how many digits 1 in [0,n]

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
            int d = (n / pow10[i]) % 10;

            ret += lftNum * pow10[i];
            if (d < 1) {
            }
            else if (d == 1) {
                ret += rhtNum + 1;
            }
            else {
                ret += pow10[i];
            }
        }

        return ret;
    }
};
