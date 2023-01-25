class Solution {
public:
    void recursion(vector<int>& diffs, size_t lo, size_t hi, int diff, long long& ret) {
        if ((hi - lo) <= 1) {
            return;
        }

        size_t mid = lo + (hi - lo) / 2;
        recursion(diffs, lo, mid, diff, ret);
        recursion(diffs, mid, hi, diff, ret);
        for (size_t i1 = lo, i2 = mid; i2 < hi; ++i2) {
            while (diffs[i1] <= (diffs[i2] + diff) && i1 < mid) {
                ++i1;
            }
            ret += (i1 - lo);
        }

        std::inplace_merge(diffs.begin() + lo, diffs.begin() + mid, diffs.begin() + hi);
    }

    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        size_t n = nums1.size();
        vector<int> diffs(n);
        for (size_t i = 0; i < n; ++i) {
            diffs[i] = nums1[i] - nums2[i];
        }

        long long ret = 0;
        recursion(diffs, 0, n, diff, ret);

        return ret;
    }
};

/*
    nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff
=>  nums1[i] - nums2[i] <= nums1[j] - nums2[j] + diff
=>  diffs[i] <= diffs[j] + diff, diffs[m] = nums1[m] - nums2[m]
*/
