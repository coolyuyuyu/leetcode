class Solution {
public:
    bool confusingNumber(int n) {
        int x = 0;
        for (int tmp = n; tmp; tmp /= 10) {
            x *= 10;
            switch (tmp % 10) {
                case 0: x += 0; break;
                case 1: x += 1; break;
                case 6: x += 9; break;
                case 8: x += 8; break;
                case 9: x += 6; break;
                default: return false;
            }
        }

        return x != n;
    }
};
