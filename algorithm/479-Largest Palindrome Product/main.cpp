class Solution {
public:
    long buildPalindrome(long n) {
        long val = n;
        while (n != 0) {
            val *= 10;
            val += (n % 10);
            n /= 10;
        }

        return val;
    }

    int largestPalindrome(int n) {
        if (n == 1) {
            return 9;
        }

        int upper = pow(10, n) - 1;
        int lower = pow(10, n - 1);
        for (int i = upper; i >= lower; --i) {
            long prod = buildPalindrome(i);
            for (long j = upper; j * j >= prod; --j) {
                if (prod % j == 0) {
                    if (prod / j > upper) {
                        break;
                    }
                    else {
                        return prod % 1337;
                    }
                }
            }
        }

        return -1;
    }
};