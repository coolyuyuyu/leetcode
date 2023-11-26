class Solution {
public:
    bool binarySearch(int x) {
        int lo = 0, hi = x;
        while (lo < hi) {
            int mid = hi - (hi - lo) / 2;
            if (1LL * mid * mid > x) {
                hi = mid - 1;
            }
            else {
                lo = mid;
            }
        }

        return lo * lo == x;
    }

    bool newtonMethod(int x) {
        int root = x;
        while (1LL * root * root > x) {
            root = (0LL + root + x / root) / 2;
        }

        return root * root == x;
    }

    bool isPerfectSquare(int num) {
        //return binarySearch(num);
        return newtonMethod(num);
    }
};
