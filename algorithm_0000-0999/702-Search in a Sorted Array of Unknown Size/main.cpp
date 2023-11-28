/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int hi = 1;
        while (reader.get(hi) < target) {
            hi <<= 1;
        }
        int lo = hi >> 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (reader.get(mid) < target) {
                lo = mid + 1;
            }
            else if (reader.get(mid) == target) {
                return mid;
            }
            else {
                hi = mid - 1;
            }
        }

        return -1;
    }
};
