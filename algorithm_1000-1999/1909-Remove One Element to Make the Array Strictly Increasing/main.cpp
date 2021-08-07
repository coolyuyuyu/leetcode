class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        assert(1 < nums.size());

        int preNum = nums[0];
        bool found = false;
        for (size_t i = 1; i < nums.size(); ++i) {
            if (preNum < nums[i]) {
                preNum = nums[i];
            }
            else {
                if (found) {
                    return false;
                }
                found = true;

                if (i == 1 || nums[i - 2] < nums[i]) {
                    preNum = nums[i];
                }
            }
        }

        return true;
    }
};
