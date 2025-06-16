class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ret = -1;
        for (int minNum = nums[0], i = 1, n = nums.size(); i < n; ++i) {
            ret = std::max(ret, (nums[i] == minNum ? -1 : nums[i] - minNum));
            minNum = std::min(minNum, nums[i]);
        }

        return ret;
    }
};
