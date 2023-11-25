class Solution {
public:
    int binarySearch(int x) {
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

        return lo;
    }

    int newtonMethod(int x) {
        int root = x;
        while (1LL * root * root > x) {
            root = (0LL + root + x / root) / 2;
        }

        return root;
    }

    int mySqrt(int x) {
        //return binarySearch(x);
        return newtonMethod(x);
    }
};
