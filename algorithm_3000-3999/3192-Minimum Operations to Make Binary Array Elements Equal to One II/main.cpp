class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ret = 0;
        for (int i = 0, n = nums.size(), flip = 0; i < n; ++i) {
            if (nums[i] == flip) {
                ++ret;
                flip = 1 - flip;
            }
        }

        return ret;
    }
};
