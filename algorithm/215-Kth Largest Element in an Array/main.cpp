class Solution {
public:
    void mysort(vector<int>& nums, size_t first, size_t last)
    {
        if (first >= last) {
            return;
        }

        swap(nums[first], nums[first + (last - first) / 2]);
        int pivot = nums[first];

        size_t lo = first;
        size_t hi = last;
        while (lo < hi) {
            do {
                ++lo;
            } while (lo + 1 < last && nums[lo] < pivot);

            do {
                --hi;
            } while (first < hi && pivot < nums[hi]);

            if (lo < hi) {
                swap(nums[lo], nums[hi]);
            }
        }
        swap(nums[first], nums[hi]);

        mysort(nums, first, hi);
        mysort(nums, hi + 1, last);
    }

    int findKthSmallestBySort(vector<int>& nums, int k) {
        mysort(nums, 0, nums.size());
        return nums[k];
    }

    int findKthSmallestByPartition(vector<int>& nums, int k) {
        size_t first = 0;
        size_t last = nums.size();

        while (first < last) {
            swap(nums[first], nums[first + (last - first) / 2]);
            int pivot = nums[first];

            size_t lo = first;
            size_t hi = last;
            while (lo < hi) {
                do {
                    ++lo;
                } while (lo + 1 < last && nums[lo] < pivot);

                do {
                    --hi;
                } while (first < hi && pivot < nums[hi]);

                if (lo < hi) {
                    swap(nums[lo], nums[hi]);
                }
            }
            swap(nums[first], nums[hi]);

            size_t lftLen = hi - first;
            if (k < lftLen) {
                last = hi;
            }
            else if (k == lftLen) {
                return nums[hi];
            }
            else {
                first = hi + 1;
                k -= (lftLen + 1);
            }
        }

        return -1;
    }

    int findKthSmallest(vector<int>& nums, int k) {
        return findKthSmallestBySort(nums, k);
        //return findKthSmallestByPartition(nums, k);
    }

    int findKthLargest(vector<int>& nums, int k) {
        return findKthSmallest(nums, nums.size() - k);
    }
};