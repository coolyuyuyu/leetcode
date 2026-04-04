class Solution {
public:
    long long countCommas(long long n) {
        long long ret = 0;
        for (long long base = 1000; base <= n; base *= 1000) {
            ret += n - base + 1;
        }

        return ret;
    }
};
