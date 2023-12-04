class Solution {
public:
    // Time: O(logn)
    int bsearch(vector<int>& arr, int k) {
        int lo = 0, hi = arr.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] - mid - 1 < k) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }

        return lo + k;
    }

    // Time: O(n)
    int lsearch(vector<int>& arr, int k) {
        for (int num : arr) {
            if (k < num) {
                break;
            }
            ++k;
        }

        return k;
    }

    int findKthPositive(vector<int>& arr, int k) {
        //return bsearch(arr, k);
        return lsearch(arr, k);
    }
};
