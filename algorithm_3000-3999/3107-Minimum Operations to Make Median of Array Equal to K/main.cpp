class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());

        int n = nums.size();
        int mid = n / 2;

        long long ret = 0;
        for (int i = 0; i <= mid; ++i) {
            ret += std::max(nums[i] - k, 0);
        }
        for (int i = mid; i < n; ++i) {
            ret += std::max(k - nums[i], 0);
        }

        return ret;
    }
};
