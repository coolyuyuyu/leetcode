class Solution {
public:
    long long removeZeros(long long n) {
        long long rev = 0;
        for (; n; n /= 10) {
            if (n % 10) {
                rev = rev * 10 + n % 10;
            }
        }

        long long ret = 0;
        for (; rev; rev /= 10) {
            ret = ret * 10 + rev % 10;
        }

        return ret;
    }
};
