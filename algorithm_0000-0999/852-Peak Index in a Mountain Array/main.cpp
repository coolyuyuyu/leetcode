class Solution {
public:
    // Time: O(n)
    int lsearch(vector<int>& arr) {
        int i = 0;
        while (arr[i] < arr[i + 1]) {
            ++i;
        }

        return i;
    }

    // Time: O(logn)
    int bsearch(vector<int>& arr) {
        int lo = 0, hi = arr.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
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
        return lsearch(arr);
        //return bsearch(arr);
    }
};
