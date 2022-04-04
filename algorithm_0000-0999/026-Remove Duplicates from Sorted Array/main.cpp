class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        assert(!nums.empty());

        size_t i = 0;
        for (size_t j = i + 1; j < nums.size(); ++j) {
            if (nums[i] < nums[j]) {
                nums[i + 1] = nums[j];
                ++i;
            }
        }
        return i + 1;
    }
};