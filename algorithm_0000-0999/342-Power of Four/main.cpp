class Solution {
public:
    bool isPowerOfFour(int n) {
        return (0 < n) && ((n & (n - 1)) == 0) && (n & 0b01010101010101010101010101010101);
    }
};
