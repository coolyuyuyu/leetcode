class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        size_t index = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[index++] = nums[i];
            }
        }

        fill(nums.begin() + index, nums.end(), 0);
    }
};