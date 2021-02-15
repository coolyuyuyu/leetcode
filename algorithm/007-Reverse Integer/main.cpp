class Solution {
public:
    int reverse(int x) {
        bool positive = (x >= 0);
        int y = 0;
        while (x) {
            if (positive) {
                if (y > ((numeric_limits<int>::max() - (x % 10)) / 10)) {
                    return 0;
                }
            }
            else {
                if (y < ((numeric_limits<int>::min() - (x % 10)) / 10)) {
                    return 0;
                }
            }
            y = y * 10 + x % 10;
            x = x / 10;
        }

        return y;
    }
};
