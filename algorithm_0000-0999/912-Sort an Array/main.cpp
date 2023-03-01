class Solution {
public:
    void quicksort(vector<int>& nums, int lo, int hi) {
        if (hi <= lo) {
            return;
        }

        // S S S S M M M M X X X X L L L
        //         i       k     j
        
        int pivot = nums[lo + (hi - lo) / 2];
        int i = lo, j = hi, k = lo;        
        while (k <= j) {
            if (nums[k] < pivot) {
                std::swap(nums[i], nums[k]);
                ++i;
                ++k;
            }
            else if (pivot < nums[k]) {
                std::swap(nums[k], nums[j]);
                --j;
            }
            else {
                ++k;
            }
        }

        // S S S S M M M M M M M L L L
        // lo      i           j     hi

        quicksort(nums, lo, i - 1);
        quicksort(nums, j + 1, hi);
    }

    void mergesort(vector<int>& nums, int lo, int hi) {
        if (hi <= lo) {
            return;
        }

        int mid = lo + (hi - lo) / 2;
        mergesort(nums, lo, mid);
        mergesort(nums, mid + 1, hi);

        vector<int> tmp(hi - lo + 1);
        int i = lo, j = mid + 1, k = 0;
        while (i <= mid && j <= hi) {
            if (nums[i] < nums[j]) {
                tmp[k++] = nums[i++];
            }
            else if (nums[j] < nums[i]) {
                tmp[k++] = nums[j++];
            }
            else {
                tmp[k++] = nums[i++];
                tmp[k++] = nums[j++];
            }
        }
        while (i <= mid) {
            tmp[k++] = nums[i++];
        }
        while (j <= hi) {
            tmp[k++] = nums[j++];
        }

        std::copy(tmp.begin(), tmp.end(), nums.begin() + lo);
    }

    vector<int> sortArray(vector<int>& nums) {
        //quicksort(nums, 0, nums.size() - 1);
        mergesort(nums, 0, nums.size() - 1);
        return nums;
    }
};
