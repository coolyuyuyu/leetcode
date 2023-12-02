class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // binary search the start index of k-length window
        int lo = 0, hi = arr.size() - k;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (x - arr[mid] > arr[mid + k] - x) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }

        return vector<int>(arr.begin() + lo, arr.begin() + lo + k);
    }
};
