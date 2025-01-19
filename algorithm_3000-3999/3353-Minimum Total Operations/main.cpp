class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ret = 0;
        for (int i = 1, n = nums.size(); i < n; ++i) {
            if (nums[i - 1] != nums[i]) {
                ++ret;
            }
        }

        return ret;
    }
};
