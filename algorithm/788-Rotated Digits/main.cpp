class Solution {
public:
    bool checkGood(int num) {
        bool different = false;
        for (int n = num; n > 0; n /= 10) {
            int digit = n % 10;
            switch (digit) {
            case 3:
            case 4:
            case 7:
                return false;
            case 0:
            case 1:
            case 8:
                break;
            case 2:
            case 5:
            case 6:
            case 9:
                different = true;
                break;
            default:
                assert(false);
            }
        }

        return different;

    }

    int rotatedDigits(int N) {
        int count = 0;
        for (int i = 1; i <= N; ++i) {
            if (checkGood(i)) {
                ++count;
            }
        }

        return count;
    }
};
