/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        for (int lo = 1, hi = n; lo <= hi;) {
            int mid = lo + (hi - lo) / 2;
            switch (guess(mid)) {
            case -1:
                hi = mid - 1;
                break;
            case 0:
                return mid;
            case 1:
                lo = mid + 1;
                break;
            }
        }

        assert(false);
        return 0;
    }
};
