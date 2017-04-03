class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (0 < n) && ((n & (n - 1)) == 0);
    }
};