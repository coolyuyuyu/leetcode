class Solution {
public:
    bool confusingNumber(int n) {
        int x = 0;
        for (int tmp = n; 0 < tmp; tmp /= 10) {
            x *= 10;

            int d = tmp % 10;
            switch (d) {
                case 2:
                case 3:
                case 4:
                case 5:
                case 7:
                    return false;
                case 6:
                    d = 9;
                    break;
                case 9:
                    d = 6;
                    break;
                default:
                    break;
            }

            x += d;
        }

        return n != x;
    }
};
