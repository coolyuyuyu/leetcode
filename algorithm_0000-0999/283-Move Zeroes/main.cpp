class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (size_t j = 0, i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                std::swap(nums[j++], nums[i]);
            }
        }
    }
};
