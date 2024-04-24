class Solution {
public:
    bool confusingNumber(int n) {
        int m = 0;
        for (int tmp = n; tmp; tmp /= 10) {
            m *= 10;
            switch (tmp % 10) {
                case 0: m += 0; break;
                case 1: m += 1; break;
                case 6: m += 9; break;
                case 8: m += 8; break;
                case 9: m += 6; break;
                default: return false;
            }
        }

        return m != n;
    }
};
