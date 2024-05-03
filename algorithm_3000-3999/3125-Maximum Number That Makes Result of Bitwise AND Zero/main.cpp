class Solution {
public:
    long long maxNumber(long long n) {
        while ((n & (n - 1)) > 0) {
            n &= (n - 1);
        }

        return n - 1;
    }
};
