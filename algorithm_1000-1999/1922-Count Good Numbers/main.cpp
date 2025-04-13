class Solution {
public:
    long long M = 1e9 + 7;

    long long quickPow(long long base, long long exp) {
        long long ret = 1;
        for (; exp; exp >>= 1) {
            if (exp & 1) {
                ret = (ret * base) % M;
            }
            base = (base * base) % M;
        }

        return ret;
    };

    int countGoodNumbers(long long n) {
        return quickPow(5, ( n + 1)/ 2) * quickPow(4, n - (n + 1) / 2) % M;
    }
};
