// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int bgn = 1;
        int end = n;
        while (true) {
            int mid = bgn + (end - bgn) / 2;
            switch (guess(mid)) {
                case 0:
                    return mid;
                case -1:
                    end = mid - 1;
                    break;
                case 1:
                    bgn = mid + 1;
                    break;
                default:
                    assert(false);
            }
        }
    }
};