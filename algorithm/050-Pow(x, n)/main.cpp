class Solution {
public:
    double myPow(double x, int n) {
        unsigned long long exp = n;
        if (n < 0) {
            x = 1 / x;
            exp = -exp;
        }

        double result = 1.0;
        while (exp) {
            if (exp & 1) {
                result *= x;
            }
            exp >>= 1;
            x *= x;
        }

        return result;
    }
};