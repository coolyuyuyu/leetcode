class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();

        nums.insert(nums.begin(), INT_MIN);
        nums.insert(nums.end(), INT_MAX);

        int lftBound = 0;
        for (; lftBound <= n; ++lftBound) {
            if (nums[lftBound] >= nums[lftBound + 1]) {
                break;
            }
        }
        if (lftBound > n) {
            return n * (n - 1) / 2 + n;
        }

        int rhtBound = n + 1;
        for (; rhtBound >= 1; --rhtBound) {
            if (nums[rhtBound - 1] >= nums[rhtBound]) {
                break;
            }
        }

        long long ret = 0;
        for (int i = 0; i <= lftBound; ++i) {
            auto itr = std::upper_bound(nums.begin() + rhtBound, nums.end(), nums[i]);
            ret += std::distance(itr, nums.end());
        }

        return ret;
    }
};
