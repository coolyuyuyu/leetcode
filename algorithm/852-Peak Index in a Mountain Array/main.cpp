class Solution {
public:
    /*
    int peakIndexInMountainArray(vector<int>& A) {
        size_t i = 0;
        while (A[i] < A[i + 1]) {
            ++i;
        }

        return i;
    }
    */

    int peakIndexInMountainArray(vector<int>& A) {
        size_t lo = 0, hi = A.size() - 1;
        while (lo < hi) {
            size_t mid = lo + (hi - lo) / 2;
            if (A[mid] < A[mid + 1]) {
                lo = mid + 1;
            }
            else {
                assert(A[mid] != A[mid + 1]);
                hi = mid;
            }
        }

        return lo;
    }
};