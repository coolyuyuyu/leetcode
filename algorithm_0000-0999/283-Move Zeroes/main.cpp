class Solution {
public:
    void moveZeroes_MoveForward(vector<int>& nums) {
        size_t preIdx = 0;
        for (size_t idx = 0; idx < nums.size(); ++idx) {
            if (nums[idx] != 0) {
                nums[preIdx++] = nums[idx];
            }
        }
        std::fill(nums.begin() + preIdx, nums.end(), 0);
    }

    void moveZeroes_SwapForward(vector<int>& nums) {
        for (size_t j = 0, i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                std::swap(nums[j++], nums[i]);
            }
        }
    }

    void moveZeroes(vector<int>& nums) {
        //return moveZeroes_MoveForward(nums);
        return moveZeroes_SwapForward(nums);
    }
};
