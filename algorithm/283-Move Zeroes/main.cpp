class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        size_t count = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[count++] = nums[i];
            }
        }

        fill(nums.begin() + count, nums.end(), 0);
    }
};