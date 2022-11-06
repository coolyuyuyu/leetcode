class Solution {
public:
    vector<int> applyOperations(vector<int> nums) {
        size_t idx = 0;
        for (size_t i = 0; (i + 1) < nums.size(); ++i) {
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
        while (idx < nums.size()) {
            nums[idx++] = 0;
        }

        return nums;
    }
};
