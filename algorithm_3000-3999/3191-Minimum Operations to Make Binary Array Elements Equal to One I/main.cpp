class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int ret = 0;
        for (int i = 0; i + 2 < n; ++i) {
            if (nums[i] == 0) {
                ++ret;
                nums[i + 1] = 1 - nums[i + 1];
                nums[i + 2] = 1 - nums[i + 2];
            }
        }

        return (nums[n - 2] == 1 && nums[n - 1] == 1) ? ret : -1;
    }
};
