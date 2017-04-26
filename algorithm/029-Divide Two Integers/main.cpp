class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor || dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        bool positive = ((dividend < 0) == (divisor < 0));
        long x = labs(dividend);
        long y = labs(divisor);
        int result = 0;
        while (y <= x) {
            long d = y;
            int exp = 1;
            while ((d << 1) <= x) {
                d <<= 1;
                exp <<= 1;
            }
            x -= d;
            result += exp;
        }

        if (!positive) {
            result = -result;
        }

        return result;
    }
};