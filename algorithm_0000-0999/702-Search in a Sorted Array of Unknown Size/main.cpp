// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:
    int searchHelper(const ArrayReader& reader, int target) {
        size_t behind = 1;
        while (reader.get(behind) < target) {
            behind <<= 1;
        }

        size_t lo = behind / 2;
        size_t hi = behind;

        while (lo <= hi) {
            size_t mid = lo + (hi - lo) / 2;
            if (reader.get(mid) == target) {
                return mid;
            }
            else if (target < reader.get(mid)) {
                if (mid == 0) {
                    return -1;
                }
                hi = mid - 1;
            }
            else {
                assert(reader.get(mid) < target);
                lo = mid + 1;
            }
        }

        return -1;
    }

    int search(const ArrayReader& reader, int target) {
        return searchHelper(reader, target);
    }
};