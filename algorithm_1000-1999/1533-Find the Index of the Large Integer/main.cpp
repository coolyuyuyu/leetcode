/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y]
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int getIndex(ArrayReader &reader) {
        int lo = 0, hi = reader.length() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if ((hi - lo + 1) & 1) {
                switch (reader.compareSub(lo, mid, mid, hi)) {
                case 1:
                    hi = mid - 1;
                    break;
                case 0:
                    lo = hi = mid;
                    break;
                case -1:
                    lo = mid + 1;
                    break;
                }
            }
            else {
                switch (reader.compareSub(lo, mid, mid + 1, hi)) {
                case 1:
                    hi = mid;
                    break;
                case 0:
                    assert(false);
                    break;
                case -1:
                    lo = mid + 1;
                    break;
                }
            }
        }

        return lo;
    }
};
