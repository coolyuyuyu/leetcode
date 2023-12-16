class Solution {
public:
    // Time: O(NlogN)
    int stdSort(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        return nums[k];
    }

    // Time: O(NlogK)
    int stdPartialSort(vector<int>& nums, int k) {
        std::partial_sort(nums.begin(), nums.begin() + k + 1, nums.end());
        return nums[k];
    }

    // Time: O(N)
    int stdNthElement(vector<int>& nums, int k) {
        std::nth_element(nums.begin(), nums.begin() + k, nums.end());
        return nums[k];
    }

    // Time: O(NlogK)
    int heap(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k + 1) {
                pq.pop();
            }
        }

        return pq.top();
    }

    // Time: O(NlogC)
    int bsearch(vector<int>& nums, int k) {
        std::function<int(int)> cntLE = [&](int target) {
            int ret = 0;
            for (int num : nums) {
                if (num <= target) {
                    ++ret;
                }
            }

            return ret;
        };

        auto [pLo, pHi] = std::minmax_element(nums.begin(), nums.end());
        auto lo = *pLo, hi = *pHi;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (cntLE(mid) > k) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }

    int qselect_recursive(vector<int>& nums, int k) {
        std::function<int(int, int, int)> f = [&](int lo, int hi, int k) {
            // M: pivot
            // S: less than pivot
            // L: greater than pivot
            // X: unknown
            // S  S  S  M  M  M  X  X  X  L  L  L
            // lo       i        x     j        hi
            int pivot = nums[lo + (hi - lo) / 2];
            int i = lo, j = hi;
            for (int x = i; x <= j;) {
                if (nums[x] < pivot) {
                    std::swap(nums[i++], nums[x++]);
                }
                else if (nums[x] == pivot) {
                    ++x;
                }
                else {
                    std::swap(nums[x], nums[j--]);
                }
            }

            // S  S  S  S  M  M  M  M  L  L  L  L
            // lo          i        j           hi
            if (k < i - lo) {
                return f(lo, i - 1, k);
            }
            else if (k < j + 1 - lo) {
                return pivot;
            }
            else {
                return f(j + 1, hi, k - (j + 1 - lo));
            }
        };

        return f(0, nums.size() - 1, k);
    }

    int qselect_iterative(vector<int>& nums, int k) {
        int lo = 0, hi = nums.size() - 1;
        for (; lo < hi;) {
            // M: pivot
            // S: less than pivot
            // L: greater than pivot
            // X: unknown
            // S  S  S  M  M  M  X  X  X  L  L  L
            // lo       i        x     j        hi
            int pivot = nums[lo + (hi - lo) / 2];
            int i = lo, j = hi;
            for (int x = i; x <= j;) {
                if (nums[x] < pivot) {
                    std::swap(nums[i++], nums[x++]);
                }
                else if (nums[x] == pivot) {
                    ++x;
                }
                else {
                    std::swap(nums[x], nums[j--]);
                }
            }

            // S  S  S  S  M  M  M  M  L  L  L  L
            // lo          i        j           hi
            if (k < i - lo) {
                hi = i - 1;
            }
            else if (k < j + 1 - lo) {
                lo = hi = i;
            }
            else {
                k = k - (j + 1 - lo);
                lo = j + 1;
            }
        };

        return nums[lo];
    }

    int findKthSmallest(vector<int>& nums, int k) {
        //return stdSort(nums, k);
        //return stdPartialSort(nums, k);
        //return stdNthElement(nums, k);
        //return heap(nums, k);
        //return bsearch(nums, k);
        //return qselect_recursive(nums, k);
        return qselect_iterative(nums, k);
    }

    int findKthLargest(vector<int>& nums, int k) {
        return findKthSmallest(nums, nums.size() - k);
    }
};
