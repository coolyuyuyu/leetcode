class Solution {
public:
    long long byDivideAndConquer(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();

        int diffs[n];
        for (int i = 0; i < n; ++i) {
            diffs[i] = nums1[i] - nums2[i];
        }

        long long ret = 0;
        std::function<void(int, int)> f = [&](int lo, int hi) {
            if (lo >= hi) { return; }

            int mid = lo + (hi - lo) / 2;
            f(lo, mid);
            f(mid + 1, hi);

            for (int i = lo, j = mid + 1; j <= hi; ++j) {
                while (i <= mid && (diffs[i] - diff <= diffs[j])) {
                    ++i;
                }
                ret += i - lo;
            }

            std::inplace_merge(diffs + lo, diffs + mid + 1, diffs + hi + 1);
        };
        f(0, n - 1);

        return ret;

    }

    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        return byDivideAndConquer(nums1, nums2, diff);
    }
};
