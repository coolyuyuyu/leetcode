class Solution {
public:
    // Time: O(nlogn)
    int minimumDifference(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());

        int ret = INT_MAX;
        for (int i = 0, n = nums.size(); i + k - 1 < n; ++i) {
            ret = std::min(ret, nums[i + k - 1] - nums[i]);
        }

        return ret;
    }
};
