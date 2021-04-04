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

    // Use decision tree to sort 5 elements within 7 steps
    void sort5Elems(vector<int>& nums, size_t first) {
        sort(nums, first, first + 5);
    }

    int findKthSmallestBestRecv(vector<int>& nums,size_t first, size_t last, size_t k) {
        size_t len = last - first;
        assert(k < len);
        if (len <= 5) {
            sort(nums, first, last);
            return nums[first + k];
        }

        int medianOfMedians = 0; {
            vector<int> medians;
            medians.reserve(len / 5);
            for (size_t start = first; start < last; start += 5) {
                size_t stop = start + 5;
                if (stop <= last) {
                    sort5Elems(nums, start);
                    medians.emplace_back(nums[start + 2]);
                }
            }

            medianOfMedians = findKthSmallestBestRecv(medians, 0, medians.size(), medians.size() / 2);
        }

        size_t len1, len2, len3;
        {
            vector<int> nums1, nums2, nums3;
            for (size_t i = first; i < last; ++i) {
                if (nums[i] < medianOfMedians) {
                    nums1.emplace_back(nums[i]);
                }
                else if (nums[i] == medianOfMedians) {
                    nums2.emplace_back(nums[i]);
                }
                else {
                    nums3.emplace_back(nums[i]);
                }
            }
            len1 = nums1.size();
            len2 = nums2.size();
            len3 = nums3.size();

            size_t i = first;
            for (size_t j = 0; j < nums1.size(); ++j) {
                nums[i++] = nums1[j];
            }
            for (size_t j = 0; j < nums2.size(); ++j) {
                nums[i++] = nums2[j];
            }
            for (size_t j = 0; j < nums3.size(); ++j) {
                nums[i++] = nums3[j];
            }
        }

        if (k < len1) {
            return findKthSmallestBestRecv(nums, first, first + len1, k);
        }
        else if (k < len1 + len2){
            return nums[first + len1];
        }
        else {
            return findKthSmallestBestRecv(nums, first + len1 + len2, last, k - len1 - len2);
        }
    }

    int findKthSmallest_Heap(const vector<int>& nums, size_t k) {
        priority_queue<int> pq; // max_heap
        for (int num : nums) {
            if (pq.size() <= (k + 1)) {
                pq.push(num);
            }
            else if (num < pq.top()) {
                pq.pop();
                pq.push(num);
            }
        }

        return pq.top();
    }

    int findKthSmallest(vector<int>& nums, size_t k) {
        //Time: O(NlogN)
        //return findKthSmallestBySort(nums, k);

        //Recursive Partition
        //Time: O(N) for average case, O(N^2) for worst case
        //return findKthSmallestByPartitionRecv(nums, 0, nums.size(), k);

        //Iterative Partition
        //Time: O(N) for average case, O(N^2) for worst case
        //return findKthSmallestByPartitionIter(nums, k);

        //Recursive Partition
        //Time: O(N) for average case, O(N) for worst case
        //return findKthSmallestBestRecv(nums, 0, nums.size(), k);

        //Heap
        //Time: O(NlogK)
        //Space: O(K)
        return findKthSmallest_Heap(nums, k);
    }

    int findKthLargest(vector<int>& nums, size_t k) {
        return findKthSmallest(nums, nums.size() - k - 1);
    }
};