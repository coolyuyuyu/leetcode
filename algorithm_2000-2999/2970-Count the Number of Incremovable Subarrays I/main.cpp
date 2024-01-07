class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
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

        int ret = 0;
        for (int lft = 0; lft <= lftBound; ++lft) {
            for (int rht = n + 1; rht >= rhtBound; --rht) {
                if (nums[lft] < nums[rht]) {
                    ++ret;
                }
            }
        }

        return ret;
    }
};
