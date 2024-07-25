class Solution {
public:
    void quicksort(vector<int>& nums, int lo, int hi) {
        if (lo >= hi) {
            return;
        }

        // S S S S M M M M ? ? ? ? ? ? L L L L
        //         i       k         j
        int pivot = nums[lo + (hi - lo) / 2];
        int i = lo, k = lo, j = hi;
        while (k <= j) {
            if (nums[k] < pivot) {
                std::swap(nums[i], nums[k]);
                ++i, ++k;
            }
            else if (nums[k] == pivot) {
                ++k;
            }
            else {
                std::swap(nums[k], nums[j]);
                --j;
            }
        }

        // S S S S S S M M M M M M L L L L L L
        // lo          i         j           hi
        quicksort(nums, lo, i - 1);
        quicksort(nums, j + 1, hi);
    }

    void mergesort(vector<int>& nums, int lo, int hi) {
        if (lo >= hi) {
            return;
        }

        int mid = lo + (hi - lo) / 2;
        mergesort(nums, lo, mid);
        mergesort(nums, mid + 1, hi);

        int i = lo, j = mid + 1, k = 0;
        vector<int> tmp(hi - lo + 1);
        while (i <= mid && j <= hi) {
            if (nums[i] < nums[j]) {
                tmp[k++] = nums[i++];
            }
            else if (nums[i] < nums[j]) {
                tmp[k++] = nums[i++];
                tmp[k++] = nums[j++];
            }
            else {
                tmp[k++] = nums[j++];
            }
        }

        std::copy(nums.begin() + i, nums.begin() + mid + 1, tmp.begin() + k);
        k += (mid - i + 1);
        std::copy(nums.begin() + j, nums.begin() + hi + 1, tmp.begin() + k);
        k += (hi - j + 1);

        std::copy(tmp.begin(), tmp.end(), nums.begin() + lo);
    }

    vector<int> sortArray(vector<int>& nums) {
        //quicksort(nums, 0, nums.size() - 1);
        mergesort(nums, 0, nums.size() - 1);
        return nums;
    }
};
