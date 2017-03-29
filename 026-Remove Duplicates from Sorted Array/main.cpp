class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        size_t index = 0;
        int val = nums.front();
        for (size_t i = 1; i < nums.size(); ++i) {
            if (val == nums[i])
                continue;
            val = nums[i];
            nums[++index] = val;
        }
        return index + 1;
    }
};