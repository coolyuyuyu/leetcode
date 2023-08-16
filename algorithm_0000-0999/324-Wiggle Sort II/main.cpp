class Solution {
public:
    // Time: O(NlogN), Space: O(N)
    void sortBeforeRearrange(vector<int>& nums) {
        int n = nums.size();

        vector<int> sorted = nums;
        std::sort(sorted.begin(), sorted.end());

        bool flag = true;
        for (int i = (n - 1) / 2, j = n - 1, k = 0; k < n; ++k) {
            if (flag) {
                nums[k] = sorted[i--];
            }
            else {
                nums[k] = sorted[j--];
            }
            flag = !flag;
        }
    }

    // Time: O(N), Space: O(N)
    void paritionByMedianBeforeRearrange(vector<int>& nums) {
        std::function<pair<int, int>(vector<int>&, int, int, int)> quickPartition = [](vector<int>& nums, int lo, int hi, int pivot) {
            // M: pivot
            // S: less than pivot
            // L: greater than pivot
            // X: unknown
            // S S S S S M M M M M X X X X X L L L L L
            //           i         x       j
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
            // lo        i       j         h

            return make_pair(i - lo, j - i + 1);
        };
        std::function<int(vector<int>&, int, int, int)> quickSelect = [&quickPartition, &quickSelect](vector<int>& nums, int lo, int hi, int k) {
            int pivot = nums[lo + (hi - lo) / 2];
            auto [s, m] = quickPartition(nums, lo, hi, pivot);
            if (k < s) {
                return quickSelect(nums, lo, lo + s - 1, k);
            }
            else if (k < (s + m)) {
                return pivot;
            }
            else {
                return quickSelect(nums, lo + s + m, hi, k - s - m);
            }
        };

        int n = nums.size();
        int medianIdx = (n - 1) / 2;
        quickSelect(nums, 0, n - 1, medianIdx);

        bool flag = true;
        auto partitioned = nums;
        for (int i = (n - 1) / 2, j = n - 1, k = 0; k < n; ++k) {
            if (flag) {
                nums[k] = partitioned[i--];
            }
            else {
                nums[k] = partitioned[j--];
            }
            flag = !flag;
        }
    }

    void wiggleSort(vector<int>& nums) {
        //sortBeforeRearrange(nums);
        paritionByMedianBeforeRearrange(nums);
    }
};
