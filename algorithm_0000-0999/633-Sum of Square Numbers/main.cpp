class Solution {
public:
    bool judgeSquareSum(int c) {
        int a = 0, b = floor(sqrt(c));
        while (a <= b) {
            long sum = 1L * a * a + 1L * b * b;
            if (sum == c) {
                return true;
            }
            else if (sum < c) {
                ++a;
            }
            else {
                --b;
            }
        }

        return false;
    }
};
