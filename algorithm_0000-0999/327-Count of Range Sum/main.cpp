class Solution {
public:
    int byDivideAndConquer(vector<int>& nums, int lower, int upper) {
        int n = nums.size() + 1;

        long presum[n];
        presum[0] = 0;
        for (int i = 1; i < n; ++i) {
            presum[i] = presum[i - 1] + nums[i - 1];
        }

        int ret = 0;
        std::function<void(int, int)> f = [&](int lo, int hi) {
            if (lo >= hi) { return; }

            int mid = lo + (hi - lo) / 2;
            f(lo, mid);
            f(mid + 1, hi);

            for (int i = lo; i <= mid; ++i) {
                auto itr1 = std::upper_bound(presum + mid + 1, presum + hi + 1, presum[i] + upper);
                auto itr2 = std::lower_bound(presum + mid + 1, presum + hi + 1, presum[i] + lower);
                ret += (itr1 - itr2);
            }

            std::inplace_merge(presum + lo, presum + mid + 1, presum + hi + 1);
        };
        f(0, n - 1);

        return ret;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        return byDivideAndConquer(nums, lower, upper);
    }
};
