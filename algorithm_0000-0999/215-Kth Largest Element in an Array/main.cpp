#define NDEBUG

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

    // Decision tree to sort 5 elements within 7 steps
    void sort5Elems(vector<int>& nums, size_t first) {
        sort(nums, first, first + 5);
    }

    int findKthSmallestBestRecv(vector<int>& nums, size_t first, size_t last, size_t k) {
        assert(first <= k && k < last);

        size_t len = last - first;
        if (len <= 5) {
            sort(nums, first, last);
            return nums[k];
        }

        int medianOfMedians; {
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

        // reorder: less than pivor, equal to pivot, larger than pivot.
        size_t smaller = first, equal = first, larger = last;
        while (equal < larger) {
            if (nums[equal] < medianOfMedians) {
                swap(nums[smaller++], nums[equal++]);
            }
            else if (nums[equal] == medianOfMedians) {
                ++equal;
            }
            else {
                swap(nums[equal], nums[--larger]);
            }
        }

        if (k < smaller) {
            return findKthSmallestBestRecv(nums, first, smaller, k);
        }
        else if (k < equal){
            return nums[smaller];
        }
        else {
            return findKthSmallestBestRecv(nums, equal, last, k);
        }
    }

    int findKthSmallest_Heap(const vector<int>& nums, size_t k) {
        priority_queue<int> pq; // max_heap
        for (int num : nums) {
            if (pq.size() <= k) {
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
        return findKthSmallestBestRecv(nums, 0, nums.size(), k);

        //Heap
        //Time: O(NlogK)
        //Space: O(K)
        //return findKthSmallest_Heap(nums, k);
    }

    int findKthLargest(vector<int>& nums, size_t k) {
        return findKthSmallest(nums, nums.size() - k);
    }
};
