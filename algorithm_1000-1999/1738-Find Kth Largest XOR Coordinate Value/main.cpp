class Solution {
public:
    // Time: O(NlogK)
    int heap(vector<vector<int>>& nums, int k) {
        int m = nums.size(), n = nums.empty() ? 0 : nums[0].size();

        priority_queue<int> pq;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                pq.push(nums[i][j]);
                if ((k + 1) < pq.size()) {
                    pq.pop();
                }
            }
        }

        return pq.top();
    }

    // Time: O(NlogC)
    int binarySearch(vector<vector<int>>& nums, int k) {
        int m = nums.size(), n = nums.empty() ? 0 : nums[0].size();

        int lo = INT_MAX, hi = INT_MIN;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                lo = std::min(lo, nums[i][j]);
                hi = std::max(hi, nums[i][j]);
            }
        }

        std::function<int(int)> countLE = [&](int target) {
            int cnt = 0;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (nums[i][j] <= target) {
                        ++cnt;
                    }
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
    int quickSelect(vector<vector<int>>& nums, int k) {
        int m = nums.size(), n = nums.empty() ? 0 : nums[0].size();
        
        std::function<int&(int)> ref = [&](int id) -> int& {
            return nums[id / n][id % n];
        };
        std::function<int(int, int, int)> f = [&](int lo, int hi, int k) {
            // M: pivot
            // S: less than pivot
            // L: greater than pivot
            // X: unknown
            // S S S S S M M M M M X X X X X L L L L L
            //           i         x       j
            //auto [r, c] = decode(lo + (hi - lo) / 2);
            int pivot = ref(lo + (hi - lo) / 2);
            int i = lo, j = hi, x = lo;
            while (x <= j) {
                if (ref(x) < pivot) {
                    std::swap(ref(i), ref(x));
                    ++i;
                    ++x;
                }
                else if (ref(x) == pivot) {
                    ++x;
                }
                else {
                    std::swap(ref(x), ref(j));
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

        return f(0, m * n - 1, k);
    }

    int kthSmallest(vector<vector<int>>& nums, int k) {
        //return heap(nums, k);
        //return binarySearch(nums, k);
        return quickSelect(nums, k);
    }

    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix.empty() ? 0 : matrix[0].size();

        vector<vector<int>> presum(m, vector<int>(n));
        presum[0][0] = matrix[0][0];
        for (int i = 1; i < m; ++i) {
            presum[i][0] = presum[i - 1][0] ^ matrix[i][0];
        }
        for (int j = 1; j < n; ++j) {
            presum[0][j] = presum[0][j - 1] ^ matrix[0][j];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                presum[i][j] = presum[i - 1][j] ^ presum[i][j - 1] ^ presum[i - 1][j - 1] ^ matrix[i][j];
            }
        }

        return kthSmallest(presum, m * n - k);
    }
};
