class Solution {
public:
    double myPow(double x, int n) {
        long long p = n;
        if (p < 0) {
            x = 1 / x;
            p = -p;
        }

        double result = 1;
        while (p > 0) {
            if (p % 2 == 1) {
                result *= x;
            }
            p /= 2;
            x *= x;
        }

        return result;
    }
};