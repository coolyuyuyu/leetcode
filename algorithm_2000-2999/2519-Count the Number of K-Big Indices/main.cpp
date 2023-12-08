class Solution {
public:
    int byDivideAndConquer(vector<int>& nums, int k) {
        int n = nums.size();

        int cntSmallerBef[n];
        std::fill(cntSmallerBef, cntSmallerBef + n, 0);
        int cntSmallerAft[n];
        std::fill(cntSmallerAft, cntSmallerAft + n, 0);

        int sorted[n];
        std::copy(nums.begin(), nums.end(), sorted);
        std::function<void(int, int)> f = [&](int lo, int hi) {
            if (lo >= hi) { return; }

            int mid = lo + (hi - lo) / 2;
            f(lo, mid);
            f(mid + 1, hi);

            for (int i = mid + 1; i <= hi; ++i) {
                cntSmallerBef[i] += std::distance(sorted + lo, std::lower_bound(sorted + lo, sorted + mid + 1, nums[i]));
            }
            for (int i = lo; i <= mid; ++i) {
                cntSmallerAft[i] += std::distance(sorted + mid + 1, std::lower_bound(sorted + mid + 1, sorted + hi + 1, nums[i]));
            }

            std::inplace_merge(sorted + lo, sorted + mid + 1, sorted + hi + 1);
        };
        f(0, n - 1);

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            if (cntSmallerBef[i] >= k && cntSmallerAft[i] >= k) {
                ++ret;
            }
        }

        return ret;
    }

    int kBigIndices(vector<int>& nums, int k) {
        return byDivideAndConquer(nums, k);
    }
};
