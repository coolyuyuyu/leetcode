class Solution {
public:

    void sort(vector<int>& nums, size_t first, size_t last) {
        assert(first <= last);

        size_t len = last - first;
        if (len < 2) {
            return;
        }

        --last;
        if (nums[last] < nums[first]) {
            swap(nums[last], nums[first]);
        }
        if (len == 2) {
            return;
        }

        size_t pivot = first + len / 2;
        if (nums[pivot] < nums[first]) {
            swap(nums[pivot], nums[first]);
        }
        if (nums[last] < nums[pivot]) {
            swap(nums[last], nums[pivot]);
        }
        if (len == 3) {
            return;
        }

        swap(nums[pivot], nums[last]);

        size_t lo = first, hi = last - 1;
        while (lo < hi) {
            while (lo < hi && nums[lo] < nums[last]) {
                ++lo;
            }
            while (lo < hi && nums[last] < nums[hi]) {
                --hi;
            }

            if (lo < hi) {
                swap(nums[lo++], nums[hi--]);
            }
        }
        if (nums[lo] < nums[last]) {
            ++lo;
        }

        swap(nums[lo], nums[last]);

        sort(nums, first, lo);
        sort(nums, lo + 1, last + 1);
    }

    int findKthSmallestBySort(vector<int>& nums, size_t k) {
        sort(nums, 0, nums.size());
        return nums[k];
    }

    int findKthSmallestByPartitionRecv(vector<int>& nums, size_t first, size_t last, size_t k) {
        assert(first <= last);

        size_t len = last - first;
        assert(k < len);

        if (len < 2) {
            return nums[first + k];
        }

        --last;
        if (nums[last] < nums[first]) {
            swap(nums[last], nums[first]);
        }
        if (len == 2) {
            return nums[first + k];
        }

        size_t pivot = first + len / 2;
        if (nums[pivot] < nums[first]) {
            swap(nums[pivot], nums[first]);
        }
        if (nums[last] < nums[pivot]) {
            swap(nums[last], nums[pivot]);
        }
        if (len == 3) {
            return nums[first + k];
        }

        swap(nums[pivot], nums[last]);

        size_t lo = first, hi = last - 1;
        while (lo < hi) {
            while (lo < hi && nums[lo] < nums[last]) {
                ++lo;
            }
            while (lo < hi && nums[last] < nums[hi]) {
                --hi;
            }

            if (lo < hi) {
                swap(nums[lo++], nums[hi--]);
            }
        }
        if (nums[lo] < nums[last]) {
            ++lo;
        }

        swap(nums[lo], nums[last]);

        size_t lftLen = lo - first;
        if (k == lftLen) {
            return nums[lo];
        }
        else if (k < lftLen) {
            return findKthSmallestByPartitionRecv(nums, first, lo, k);
        }
        else {
            return findKthSmallestByPartitionRecv(nums, lo + 1, last + 1, k - lftLen - 1);
        }
    }

    int findKthSmallestByPartitionIter(vector<int>& nums, size_t k) {
        size_t first = 0, last = nums.size();
        while (first < last) {
            size_t len = last - first;
            assert(k < len);

            if (len < 2) {
                return nums[first + k];
            }

            --last;
            if (nums[last] < nums[first]) {
                swap(nums[last], nums[first]);
            }
            if (len == 2) {
                return nums[first + k];
            }

            size_t pivot = first + len / 2;
            if (nums[pivot] < nums[first]) {
                swap(nums[pivot], nums[first]);
            }
            if (nums[last] < nums[pivot]) {
                swap(nums[last], nums[pivot]);
            }
            if (len == 3) {
                return nums[first + k];
            }

            swap(nums[pivot], nums[last]);

            size_t lo = first, hi = last - 1;
            while (lo < hi) {
                while (lo < hi && nums[lo] < nums[last]) {
                    ++lo;
                }
                while (lo < hi && nums[last] < nums[hi]) {
                    --hi;
                }

                if (lo < hi) {
                    swap(nums[lo++], nums[hi--]);
                }
            }
            if (nums[lo] < nums[last]) {
                ++lo;
            }

            swap(nums[lo], nums[last]);

            size_t lftLen = lo - first;
            if (k == lftLen) {
                return nums[lo];
            }
            else if (k < lftLen) {
                last = lo;
            }
            else {
                first = lo + 1;
                ++last;
                k -= (lftLen + 1);
            }
        }

        assert(false);
    }

    int findKthSmallest(vector<int>& nums, size_t k) {
        //Time: T(n) = O(nlogn)
        //return findKthSmallestBySort(nums, k);

        //Recursive Partition
        //Time: T(n) = O(n) for average case, O(n^2) for worst case
        //return findKthSmallestByPartitionRecv(nums, 0, nums.size(), k);

        //Iterative Partition
        //Time: T(n) = O(n) for average case, O(n^2) for worst case
        return findKthSmallestByPartitionIter(nums, k);
    }

    int findKthLargest(vector<int>& nums, size_t k) {
        return findKthSmallest(nums, nums.size() - k);
    }
};