class Solution {
public:
    int peakIndexInMountainArrayLinearSearch(vector<int>& A) {
        size_t i = 0;
        while (A[i] < A[i + 1]) {
            ++i;
        }

        return i;
    }

    int peakIndexInMountainArrayBinarySearch(const vector<int>& A) {
        size_t lo = 0;
        size_t hi = A.size() - 1;

        while (lo < hi) {
            size_t mid = lo + (hi - lo) / 2;
            if (A[mid] < A[mid + 1]) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }

        assert(lo == hi);
        return lo;
    }

    int peakIndexInMountainArray(vector<int>& A) {
        //return peakIndexInMountainArrayLinearSearch(A);

        return peakIndexInMountainArrayBinarySearch(A);
    }
};