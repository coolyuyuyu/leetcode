class Solution {
public:
    int sumDigits(long long n) {
        int d = 0;
        for (; n; n /= 10) {
            d += (n % 10);
        }

        return d;
    }

    long long makeIntegerBeautiful(long long n, int target) {
        long long x = 0;
        for (long long base = 1; target < sumDigits(n); base *= 10, n /= 10) {
            int digit = n % 10;
            if (0 < digit) {
                x += ((10 - digit) * base);
                n += (10 - digit);
            }
        }

        return x;
    }
};
