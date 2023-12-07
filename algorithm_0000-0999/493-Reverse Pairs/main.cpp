class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();

        int sorted[n];
        std::copy(nums.begin(), nums.end(), sorted);

        int ret = 0;
        std::function<void(int, int)> f = [&](int lo, int hi) {
            if (lo >= hi) { return; }

            int mid = lo + (hi - lo) / 2;
            f(lo, mid);
            f(mid + 1, hi);

            for (int j = mid + 1; j <= hi; ++j) {
                ret += std::distance(std::upper_bound(sorted + lo, sorted + mid + 1, 1L * nums[j] * 2), sorted + mid + 1);
            }

            std::inplace_merge(sorted + lo, sorted + mid + 1, sorted + hi + 1);
        };
        f(0, n - 1);

        return ret;
    }
};
