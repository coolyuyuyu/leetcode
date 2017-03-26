class Solution {
public:
    int reverse(int x) {
        int y = 0;
        while (x) {
            int tmp = y;
            y *= 10;
            y += x % 10;
            if (y / 10 != tmp) {
                return 0;
            }
            x /= 10;
        }
        return y;
    }
};
