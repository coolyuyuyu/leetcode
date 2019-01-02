class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while (m < n) {
            n = n & (n - 1); // clear last bit
        }

        return n;
    }
};