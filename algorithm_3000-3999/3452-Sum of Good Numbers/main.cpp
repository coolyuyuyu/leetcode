class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int ret = 0;
        for (int i = 0, n = nums.size(); i < n; ++i) {
            if (i - k >= 0 && nums[i - k] >= nums[i]) { continue; }
            if (i + k < n && nums[i] <= nums[i + k]) { continue; }
            ret += nums[i];
        }

        return ret;
    }
};
