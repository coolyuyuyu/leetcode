class Solution {
public:
    int findNthDigit(int n) {
        long base = 9;
        int digit = 1;
        while ((base * digit) < n) {
            n -= (base * digit);
            base *= 10;
            digit += 1;
        }

        int index = n % digit;
        if (index == 0) {
            index = digit;
        }

        int num = 1;
        for (int i = 1; i < digit; ++i) {
            num *= 10;
        }
        num += ((index == digit) ? (n / digit - 1) : (n / digit));

        for (int i = index; i < digit; ++i) {
            num /= 10;
        }

        return num % 10;

    }
};