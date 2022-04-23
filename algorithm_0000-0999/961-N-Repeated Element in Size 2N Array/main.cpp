class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        if (nums.size() == 4 && nums[0] == nums[3]) {
            return nums[0];
        }
        for (size_t i = 0; (i + 1) < nums.size(); ++i) {
            if (nums[i] == nums[i + 1]) {
                return nums[i];
            }
            else if ((i + 2) < nums.size() && nums[i] == nums[i + 2]) {
                return nums[i];
            }
        }

        return -1;
    }
};
