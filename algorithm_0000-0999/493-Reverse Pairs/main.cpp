class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<int> sorted(nums);

        int ret = 0;
        std::function<void(int, int)> f = [&](int lo, int hi) {
            if (hi <= lo) {
                return;
            }

            int mid = lo + (hi - lo) / 2;
            f(lo, mid);
            f(mid + 1, hi);

            for (int i = mid + 1; i <= hi; ++i) {
                ret += std::distance(std::upper_bound(sorted.begin() + lo, sorted.begin() + mid + 1, (long)nums[i] * 2), sorted.begin() + mid + 1);
            }

            std::inplace_merge(sorted.begin() + lo, sorted.begin() + mid + 1, sorted.begin() + hi + 1);
        };
        f(0, sorted.size() - 1);

        return ret;
    }
};
