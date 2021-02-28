class Solution {
public:
    int trailingZeroes(int n) {
        long long count = 0;
        long long base = 1;
        do {
            base *= 5;
            count += (n / base);
        } while (base <= n);
        
        return count;
    }
};