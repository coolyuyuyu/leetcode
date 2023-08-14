class Solution {
public:
    // Time: O(NlogN)
    int quickSort(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        return nums[k];
    }

    // Time: O(NlogK)
    int heap(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (int num : nums) {
            pq.push(num);
            if ((k+1) < pq.size()) {
                pq.pop();
            }
        }

        return pq.top();
    }

    // Time: O(NlogC)
    int binarySearch(vector<int>& nums, int k) {
        auto [pLo, pHi] = std::minmax_element(nums.begin(), nums.end());
        auto lo = *pLo, hi = *pHi;

        std::function<int(int)> countLE = [&nums, k](int target) {
            int cnt = 0;
            for (int num : nums) {
                if (num <= target) {
                    ++cnt;
                }
            }

            return cnt;
        };
        while (lo < hi) {
            auto mid = lo + (hi - lo) / 2;
            if (k < countLE(mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }

    // Time: Amoterized O(N)
    int quickSelect(vector<int>& nums, int k) {
        std::function<int(int, int, int)> f = [&](int lo, int hi, int k) {
            // M: pivot
            // S: less than pivot
            // L: greater than pivot
            // X: unknown
            // S S S S S M M M M M X X X X X L L L L L
            //           i         x       j
            int pivot = nums[lo + (hi - lo) / 2];
            int i = lo, j = hi, x = lo;
            while (x <= j) {
                if (nums[x] < pivot) {
                    std::swap(nums[i], nums[x]);
                    ++i;
                    ++x;
                }
                else if (nums[x] == pivot) {
                    ++x;
                }
                else {
                    std::swap(nums[x], nums[j]);
                    --j;
                }
            }
            // S S S S S M M M M M L L L L L
            // lo        i       j         hi
            if (k < (i - lo)) {
                return f(lo, i - 1, k);
            }
            else if (k < (j + 1 - lo)) {
                return pivot;
            }
            else {
                return f(j + 1, hi, k - (j + 1 - lo));
            }
        };

        return f(0, nums.size() - 1, k);
    }

    int findKthSmallest(vector<int>& nums, int k) {
        //return quickSort(nums, k);
        //return heap(nums, k);
        //return binarySearch(nums, k);
        return quickSelect(nums, k);
    }

    int findKthLargest(vector<int>& nums, int k) {
        return findKthSmallest(nums, nums.size() - k);
    }
};
