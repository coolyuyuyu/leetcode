class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int idx = 0;
        for (int i = 0; i + 1 < nums.size(); ++i) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
            if (nums[i] != 0) {
                nums[idx++] = nums[i];
            }
        }
        if (nums.back() != 0) {
            nums[idx++] = nums.back();
        }
        std::fill(nums.begin() + idx, nums.end(), 0);

        return nums;
    }
};
