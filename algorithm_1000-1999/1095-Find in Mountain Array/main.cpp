/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        int lo = 1, hi = n - 2;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }

        int pivot = lo;
        if (mountainArr.get(pivot) == target) {
            return pivot;
        }

        if (mountainArr.get(0) <= target && target < mountainArr.get(pivot)) {
            lo = 0, hi = pivot - 1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                int num = mountainArr.get(mid);
                if (target < num) {
                    hi = mid - 1;
                }
                else if (target == num) {
                    return mid;
                }
                else {
                    lo = mid + 1;
                }
            }
        }

        if (mountainArr.get(pivot) > target && target >= mountainArr.get(n - 1)) {
            lo = pivot + 1, hi = n - 1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                int num = mountainArr.get(mid);
                if (target > num) {
                    hi = mid - 1;
                }
                else if (target == num) {
                    return mid;
                }
                else {
                    lo = mid + 1;
                }
            }
        }

        return -1;
    }
};
