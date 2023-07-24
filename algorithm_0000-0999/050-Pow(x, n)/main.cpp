class Solution {
public:
    double recursive(double x, int n) {
        std::function<double(double, long)> f = [&](double x, long exp) {
            if (exp == 0) {
                return 1.0;
            }
            else if (exp & 1) {
                return x * f(x * x, exp >> 1);
            }
            else {
                return f(x * x, exp >> 1);
            }
        };

        long long exp = n;
        if (exp < 0) {
            exp = -exp;
            x = 1 / x;
        }

        return f(x, exp);
    }

    double iterative(double x, int n) {
        long long exp = n;
        if (exp < 0) {
            exp = -exp;
            x = 1 / x;
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
        return recursive(x, n);
        //return iterative(x, n);
    }
};
