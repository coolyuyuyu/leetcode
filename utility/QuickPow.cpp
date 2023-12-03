// Leetcode 50. Pow(x, n)

class Solution {
public:
    double recursive(double x, int n) {
        std::function<double(double, long)> f = [&](double x, long n) {
            if (n == 0) { return 1.0; }
            else if (n & 1) { return x * f(x * x, n >> 1); }
            else { return f(x * x, n >> 1); }
        };

        long exp = n;
        if (exp < 0) {
            x = 1.0 / x;
            exp = -exp;
        }

        return f(x, exp);
    }

    double iterative(double x, int n) {
        long exp = n;
        if (exp < 0) {
            exp = -exp;
            x = 1.0 / x;
        }

        double ret = 1.0;
        for (; exp; exp >>= 1) {
            if (exp & 1) {
                ret *= x;
            }
            x *= x;
        }

        return ret;
    }

    double myPow(double x, int n) {
        //return recursive(x, n);
        return iterative(x, n);
    }
};
