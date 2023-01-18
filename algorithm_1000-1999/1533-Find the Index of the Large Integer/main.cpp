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
        int lft = 0, rht = reader.length() - 1;
        while (lft < rht) {
            int mid = lft + (rht - lft) / 2;
            if ((rht - lft) % 2) { // even number of elements
                int result = reader.compareSub(lft, mid, mid + 1, rht);
                if (result == 1) {
                    rht = mid;
                }
                else {
                    assert(result == -1);
                    lft = mid + 1;
                }
            }
            else {
                int result = reader.compareSub(lft, mid - 1, mid + 1, rht);
                if (result == 1) {
                    rht = mid - 1;
                }
                else if (result == 0) {
                    lft = rht = mid;
                }
                else {
                    lft = mid + 1;
                }
            }
        }

        return lft;
    }
};
