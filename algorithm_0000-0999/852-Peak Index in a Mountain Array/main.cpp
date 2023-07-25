class Solution {
public:
    // Time: O(N), linear search
    int linearSearch(vector<int>& arr) {
        for (size_t i = 1; i < arr.size(); ++i) {
            if (arr[i - 1] > arr[i]) {
                return i - 1;
            }
        }

        assert(false);
        return -1;
    }

    // Time: O(N), binary search
    int binarySearch(vector<int>& arr) {
        size_t lo = 0, hi = arr.size() - 1;
        while (lo < hi) {
            size_t mid = lo + (hi - lo) / 2;
            if (arr[mid] < arr[mid + 1]) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }

        return lo;
    }

    int peakIndexInMountainArray(vector<int>& arr) {
        //return linearSearch(arr);
        return binarySearch(arr);
    }
};
