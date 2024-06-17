class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        int ret = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] < nums[i]) { continue; }
            ret += nums[i - 1] + 1 - nums[i];
            nums[i] = nums[i - 1] + 1;
        }

        return ret;
    }
};
