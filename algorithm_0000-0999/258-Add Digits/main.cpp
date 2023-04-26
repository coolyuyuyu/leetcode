class Solution {
public:
    int bruteforce(int num) {
        while (10 <= num) {
            int tmp = 0;
            for (; num; num /= 10) {
                tmp += (num % 10);
            }
            num = tmp;
        }

        return num;
    }

    int math(int num) {
        // n can be presented in a way that d0, d1, d2, ..., dk are digits of n
        // n = d0 + d1 * 10^1 + d2 * 10^2 + ... + dk * 10^k
        // n = d0 + d1 * (9 + 1) + d2 * (99 + 1) + d3 * (999 + 1) + ... + dk * (999...9 + 1)
        // n = d0 + d1 + d2 + ... + dk + 9 * (d1 * 1 + d2 * 11 + d3 * 111 + ... + dk * 111...1)
        // n mod 9 = (d0 + d1 + d2 + ... + dk) mod 9

        if (num == 0) {
            return 0;
        }
        if (num % 9 == 0) {
            return 9;
        }
        return num % 9;
    }

    int addDigits(int num) {
        //return bruteforce(num);
        return math(num);
    }
};
