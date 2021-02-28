class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        size_t wIndex = 2;
        for (size_t rIndex = 2; rIndex < nums.size() ; ++ rIndex) {
            if (nums[wIndex - 2] < nums[rIndex]) {
                nums[wIndex++] = nums[rIndex];
            }
        }

        return nums.size() < 2 ? nums.size() : wIndex;
    }
};