class Solution {
public:
    int maximum69Number (int num) {
        int targetPos = -1;
        for (int tmp = num, pos = 0; tmp; tmp /= 10, ++pos) {
            if (tmp % 10 == 6) {
                targetPos = pos;
            }
        }

        if (0 <= targetPos) {
            int tmp = 3;
            while (targetPos--) {
                tmp *= 10;
            }
            num += tmp;
        }

        return num;
    }
};
