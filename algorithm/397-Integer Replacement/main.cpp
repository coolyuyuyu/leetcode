class Solution {
public:
    int integerReplacement(int n) {
        int count = 0;
        if (n == numeric_limits<int>::max()) {
            n -= 1;
            n /= 2;
            n += 1;
            count = 2;
        }
        while (n > 1) {
            if ((n & 1) == 0) {
                n /= 2;
            }
            else {
                if (n != 3 && (n & 2) == 2) {
                    n += 1;
                }
                else {
                    n -= 1;
                }
            }
            count++;
        }
        return count;
    }
};