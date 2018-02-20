class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool foundDisordered = false;
        size_t index = 0;
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] > nums[i]) {
                if (foundDisordered) {
                    return false;
                }
                foundDisordered = true;
                index = i;
            }
        }

        return foundDisordered == false
            || index == 1 
            || index == nums.size() - 1 
            || nums[index - 1] <= nums[index + 1] 
            || nums[index - 2] <= nums[index];
    }
};