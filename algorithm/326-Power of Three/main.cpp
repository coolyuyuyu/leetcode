class Solution {
public:
    // slow
    bool isPowerOfThree(int n) {
        if (n == 0) {
            return false;
        }

        while (n % 3 == 0) {
            n /= 3;
        }
        
        return n == 1;
    }

    // fast
    bool isPowerOfThree(int n) {
        static int MAX_POWER_OF_3 = 1162261467;
        return 0 < n && MAX_POWER_OF_3 % n == 0;
    }
};