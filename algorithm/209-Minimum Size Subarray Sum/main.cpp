class Solution {
public:
    size_t minSubArrayLen(int s, vector<int>& nums) {
        assert(0 < s);

        vector<int> sums(nums.size());
        partial_sum(nums.begin(), nums.end(), sums.begin());

        auto itr = lower_bound(sums.begin(), sums.end(), s);
        if (itr == sums.end()) {
            return 0;
        }

        size_t len = itr - sums.begin() + 1;
        for (size_t i = 0; i < nums.size(); ++i) {
            size_t end = min(len + i - 1, nums.size());
            for (size_t j = i; j < end; ++j) {
                if (sums[j] - sums[i - 1] >= s) {
                    len = min(len, j - i + 1);
                    break;
                }
            }
        }

        return len;
    }
};